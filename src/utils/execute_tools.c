/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_tools.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmote <hmote@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 14:43:21 by hmote             #+#    #+#             */
/*   Updated: 2025/08/19 15:48:10 by hmote            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	compact_args(char **args)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (args[i])
	{
		if (args[i][0] != '\0')
		{
			args[j] = args[i];
			j++;
		}
		else
			free(args[i]);
		i++;
	}
	args[j] = NULL;
}

int	is_literal(const char *line, char c)
{
	int		i;
	char	quote;

	i = 0;
	quote = 0;
	while (line[i])
	{
		if ((line[i] == '\'' || line[i] == '\"'))
		{
			if (quote == 0)
				quote = line[i];
			else if (quote == line[i])
				quote = 0;
		}
		else if (line[i] == c && quote == 0)
			return (1);
		i++;
	}
	return (0);
}

int	is_directory(const char *path)
{
	struct stat	st;

	if (stat(path, &st) == 0)
		return (S_ISDIR(st.st_mode));
	return (0);
}

int	is_executable(char *path)
{
	struct stat	sb;

	if (stat(path, &sb) == 0 && (sb.st_mode & S_IXUSR))
		return (1);
	return (0);
}

int	is_builtin(char *cmd)
{
	return (!ft_strcmp(cmd, "cd")
		|| !ft_strcmp(cmd, "echo")
		|| !ft_strcmp(cmd, "pwd")
		|| !ft_strcmp(cmd, "exit")
		|| !ft_strcmp(cmd, "export")
		|| !ft_strcmp(cmd, "unset")
		|| !ft_strcmp(cmd, "env"));
}
