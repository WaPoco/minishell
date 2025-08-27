/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpogorel <vpogorel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 22:37:28 by hmote             #+#    #+#             */
/*   Updated: 2025/07/25 13:38:18 by vpogorel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static void	put_escaped(const char *s, int interpret)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (interpret && s[i] == '\\')
		{
			if (s[i + 1] == 'n')
				write(1, "\n", 1);
			else if (s[i + 1] == 't')
				write(1, "\t", 1);
			else if (s[i + 1] == '\\')
				write(1, "\\", 1);
			else
				write(1, &s[i + 1], 1);
			i += 2;
		}
		else
		{
			write(1, &s[i], 1);
			i++;
		}
	}
}

static int	rest_same(char *arg, char c)
{
	int	i;

	if (!arg || arg[0] != '-')
		return (0);
	i = 1;
	if (arg[i] == '\0')
		return (0);
	while (arg[i])
	{
		if (arg[i] != c)
			return (0);
		i++;
	}
	return (1);
}

static int	parse_flags(char *arg, int *newline, int *interpret)
{
	if (rest_same(arg, 'n'))
		*newline = 0;
	else if (rest_same(arg, 'e'))
		*interpret = 1;
	else if (ft_strcmp(arg, "-ne") == 0 || ft_strcmp(arg, "-en") == 0)
	{
		*newline = 0;
		*interpret = 1;
	}
	else
		return (0);
	return (1);
}

int	builtin_echo(char **args)
{
	int	i;
	int	newline;
	int	interpret;

	newline = 1;
	interpret = 0;
	i = 1;
	while (args[i] && args[i][0] == '-' && args[i][1])
	{
		if (!parse_flags(args[i], &newline, &interpret))
			break ;
		i++;
	}
	while (args[i])
	{
		put_escaped(args[i], interpret);
		if (args[i + 1])
			write(1, " ", 1);
		i++;
	}
	if (newline)
		write(1, "\n", 1);
	return (0);
}
