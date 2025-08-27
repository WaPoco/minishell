/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpogorel <vpogorel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 15:55:56 by hmote             #+#    #+#             */
/*   Updated: 2025/07/25 13:36:54 by vpogorel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

/* 
	To simiulate the original exit we have to write exit
	and then call the exit function of c which is allowed by the subject
	if we have extra arguments, shouldn't exit, only displaying an informational err
*/

int	builtin_exit(t_shell *shell, char **args)
{
	write(1, "exit\n", 5);
	if (args[1])
	{
		if (!ft_isnumeric(args[1]))
		{
			write(2, " numeric argument required\n", 27);
			g_sigint = 2;
		}
		else if (args[2])
		{
			write(2, " too many arguments\n", 19);
			write(STDOUT_FILENO, "\n", 1);
			g_sigint = 1;
			return (1);
		}
		else
		{
			if (ft_atoi(args[1]) < 0)
				g_sigint = (ft_atoi(args[1]) % 256 + 256) % 256;
			else
				g_sigint = ft_atoi(args[1]) % 256;
		}
	}
	shell->should_exit = 1;
	return (g_sigint);
}
