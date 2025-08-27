/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmote <hmote@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 23:41:59 by hmote             #+#    #+#             */
/*   Updated: 2025/04/18 10:29:28 by hmote            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* 	To print all environment variables that have a '=' in them.
	Not printing variables that have no "=" (compare with export)
*/

#include "../../include/minishell.h"

int	builtin_env(char **env)
{
	int	i;

	i = 0;
	while (env[i])
	{
		if (ft_strchr(env[i], '='))
		{
			write(1, env[i], ft_strlen(env[i]));
			write(1, "\n", 1);
		}
		i++;
	}
	return (0);
}
