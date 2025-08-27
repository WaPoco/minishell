/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpogorel <vpogorel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 00:13:51 by hmote             #+#    #+#             */
/*   Updated: 2025/07/25 13:29:45 by vpogorel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * Main function that parses the line and executes the command.
 * It splits the line we got it from the user in the minishell command line
 * Then, it executes the command in two ways; either is a builtin command like cd
 * 	or is a name of a executable file in the adresses ritten in the PATH variable
 * 	to see the invoronment variable PATH we can write env or export in the shell 
 * ---> it should be checked for memory leack
 */

#include "../include/minishell.h"

static void	exec_builtin_cmd(t_shell *shell, char **args, t_redirect *redir)
{
	if (apply_redirections(redir, shell) != 0)
	{
		g_sigint = 1;
		return ;
	}
	g_sigint = execute_builtin(shell, args);
	reset_std_fds(shell);
}

/*
** Execute external command in child process
*/
static void	exec_external_cmd(t_shell *shell, char **args, t_redirect *redir)
{
	pid_t	pid;
	int		status;

	pid = fork();
	if (pid == 0)
	{
		if (apply_redirections(redir, shell) != 0)
			exit(1);
		execute_external(shell, args);
		free_redirection(redir);
		exit(0);
	}
	else if (pid > 0)
	{
		signal(SIGINT, SIG_IGN);
		waitpid(pid, &status, 0);
		g_sigint = WEXITSTATUS(status);
		if (WTERMSIG(status) == SIGINT)
			write(STDOUT_FILENO, "\n", 1);
		else if (WTERMSIG(status) == SIGQUIT)
			write(STDOUT_FILENO, "Quit (core dumped)\n", 19);
		reset_std_fds(shell);
	}
	else
		perror("minishell: fork");
}

static void	exec_command(t_shell *shell, char **args)
{
	t_redirect	redir;

	shell->stdin_save = dup(STDIN_FILENO);
	shell->stdout_save = dup(STDOUT_FILENO);
	handle_redirections(args, &redir);
	if (args[0] && is_builtin(args[0]))
		exec_builtin_cmd(shell, args, &redir);
	else
		exec_external_cmd(shell, args, &redir);
	if (redir.in != -1)
		close(redir.in);
	if (redir.out != -1)
		close(redir.out);
	free_redirection(&redir);
}

void	execute_plain(t_shell *shell, char *line)
{
	char	**args;

	args = tokenize(line, shell);
	if (!args)
		return ;
	compact_args(args);
	if (!args[0])
	{
		free_arr(args);
		return ;
	}
	exec_command(shell, args);
	free_arr(args);
}

void	parse_and_execute(t_shell *shell, char *line)
{
	if (ft_strchr(line, '|') && is_literal(line, '|'))
		execute_pipeline(shell, line);
	else
		execute_plain(shell, line);
}
