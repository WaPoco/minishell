/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_helper.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmote <hmote@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 15:41:07 by hmote             #+#    #+#             */
/*   Updated: 2025/08/19 15:48:54 by hmote            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

char	*make_full_path(const char *path, const char *cmd)
{
	size_t	path_len;
	size_t	cmd_len;
	char	*full;

	path_len = ft_strlen(path);
	cmd_len = ft_strlen(cmd);
	full = malloc(path_len + cmd_len + 2);
	if (!full)
		return (NULL);
	ft_memcpy(full, path, path_len);
	full[path_len] = '/';
	ft_memcpy(full + path_len + 1, cmd, cmd_len);
	full[path_len + cmd_len + 1] = '\0';
	return (full);
}

void	execute_fork(t_shell *shell, char **args, int *status)
{
	pid_t	pid;
	int		exit_status;

	pid = fork();
	if (pid == 0)
		execute_external(shell, args);
	else
	{
		waitpid(pid, status, 0);
		exit_status = WEXITSTATUS(*status);
		g_sigint = exit_status;
	}
}
