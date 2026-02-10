/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmote <hmote@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 14:06:48 by hmote             #+#    #+#             */
/*   Updated: 2025/04/19 14:52:12 by hmote            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static void	unset_env_var(t_shell *shell, int index)
{
	int	k;

	free(shell->env[index]);
	k = index;
	while (shell->env[k])
	{
		shell->env[k] = shell->env[k + 1];
		k++;
	}
}

int	builtin_unset(t_shell *shell, char **args)
{
	int	i;
	int	j;

	i = 1;
	while (args[i])
	{
		j = 0;
		while (shell->env[j])
		{
			if (!ft_strncmp(shell->env[j], args[i], ft_strlen(args[i]))
				&& shell->env[j][ft_strlen(args[i])] == '=')
			{
				unset_env_var(shell, j);
				break ;
			}
			j++;
		}
		i++;
	}
	return (0);
}
