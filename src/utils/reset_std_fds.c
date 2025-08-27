/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset_std_fds.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpogorel <vpogorel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 16:38:44 by hmote             #+#    #+#             */
/*   Updated: 2025/07/25 13:40:27 by vpogorel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	reset_std_fds(t_shell *shell)
{
	if (shell->stdin_save != -1)
	{
		dup2(shell->stdin_save, STDIN_FILENO);
		close(shell->stdin_save);
	}
	if (shell->stdout_save != -1)
	{
		dup2(shell->stdout_save, STDOUT_FILENO);
		close(shell->stdout_save);
	}
}
