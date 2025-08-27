/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipeline_tools.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpogorel <vpogorel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 12:41:15 by vpogorel          #+#    #+#             */
/*   Updated: 2025/07/25 12:44:26 by vpogorel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	setup_fds(char **cmds, int i, int *fds)
{
	if (fds[0] != -1)
	{
		dup2(fds[0], STDIN_FILENO);
		close(fds[0]);
	}
	if (cmds[i + 1])
	{
		close(fds[2]);
		dup2(fds[3], STDOUT_FILENO);
		close(fds[3]);
	}
}

int	wait_all_children(int count, pid_t *pids)
{
	int	i;
	int	status;
	int	last_exit;

	i = 0;
	last_exit = 0;
	while (i < count)
	{
		waitpid(pids[i], &status, 0);
		if (WIFEXITED(status))
			last_exit = WEXITSTATUS(status);
		else if (WIFSIGNALED(status))
			last_exit = 128 + WTERMSIG(status);
		i++;
	}
	return (last_exit);
}
