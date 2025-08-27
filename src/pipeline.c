/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipeline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpogorel <vpogorel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 14:35:41 by hmote             #+#    #+#             */
/*   Updated: 2025/07/25 13:35:03 by vpogorel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static void	exec_command(t_shell *shell, char **args)
{
	t_redirect	redir;
	int			ret;

	ret = 0;
	handle_redirections(args, &redir);
	if (apply_redirections(&redir, shell) != 0)
		ret = 1;
	else if (is_builtin(args[0]))
		ret = execute_builtin(shell, args);
	else
		execute_external(shell, args);
	free_redirection(&redir);
	exit(ret);
}

void	child_process(t_shell *shell, char *line)
{
	char	**args;

	args = tokenize(line, shell);
	if (!args)
		exit(1);
	compact_args(args);
	if (!args[0])
	{
		free_arr(args);
		exit(0);
	}
	exec_command(shell, args);
	free_arr(args);
	exit(g_sigint);
}

static void	update_fds(int *fds, char has_next)
{
	if (fds[0] != -1)
		close(fds[0]);
	if (has_next)
	{
		close(fds[3]);
		fds[0] = fds[2];
	}
	else
		fds[0] = -1;
}

/*
** Spawn child processes for each command in a pipeline
*/
int	spawn_processes(t_shell *shell, char **cmds, pid_t *pids)
{
	pid_t	pid;
	int		fds[4];
	int		i;

	fds[0] = -1;
	i = 0;
	while (cmds[i])
	{
		if (cmds[i + 1] && pipe(&fds[2]) == -1)
			return (perror("pipe"), 1);
		pid = fork();
		if (pid == -1)
			return (perror("fork"), 1);
		if (pid == 0)
		{
			setup_fds(cmds, i, fds);
			child_process(shell, cmds[i]);
		}
		pids[i] = pid;
		update_fds(fds, cmds[i + 1] != NULL);
		i++;
	}
	return (0);
}

int	execute_pipeline(t_shell *shell, char *line)
{
	char	**cmds;
	int		cmd_count;
	pid_t	*pids;

	cmds = ft_split_quotes(line, '|');
	if (!cmds)
		return (1);
	cmd_count = 0;
	while (cmds[cmd_count])
		cmd_count++;
	pids = malloc(sizeof(pid_t) * cmd_count);
	if (!pids)
		return (free_arr(cmds), 1);
	if (spawn_processes(shell, cmds, pids))
		return (free(pids), free_arr(cmds), 1);
	g_sigint = wait_all_children(cmd_count, pids);
	free (pids);
	free_arr(cmds);
	return (g_sigint);
}
