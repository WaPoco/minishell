/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpogorel <vpogorel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 23:53:47 by hmote             #+#    #+#             */
/*   Updated: 2025/07/25 13:17:07 by vpogorel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

/**
 * Splits a line by spaces.
 * Later, we'll improve this to handle quotes.
 * 
 * "token" is a name refers to the user's command typed in the command line
 * and I try to keep this naming over the whole programm
 */
static char	*space_alloc(char *line)
{
	char	*new;
	int		count;
	int		i;

	count = 0;
	i = 0;
	while (line[i])
	{
		if (!is_quoted(i, line)
			&& (line[i] == '<' || line[i] == '>'))
		{
			count++;
			if (!is_quoted(i, line) && (line[i + 1]
					&& (line[i + 1] == '<' || line[i + 1] == '>')))
				i++;
		}
		i++;
	}
	new = malloc(sizeof(char) * (i + 2 * count + 1));
	if (!new)
		return (NULL);
	return (new);
}

static char	*space_line(char *line)
{
	char	*new;
	int		i;
	int		j;

	i = 0;
	j = 0;
	new = space_alloc(line);
	if (!new)
		return (NULL);
	while (new && line[i])
	{
		if (!is_quoted(i, line) && (line[i] == '<' || line[i] == '>'))
		{
			new[j++] = ' ';
			new[j++] = line[i++];
			if (!is_quoted(i, line) && (line[i] == '>' || line[i] == '<'))
				new[j++] = line[i++];
			new[j++] = ' ';
		}
		else
			new[j++] = line[i++];
	}
	new[j] = '\0';
	return (new);
}

char	**tokenize(char *line, t_shell *shell)
{
	char	**tokens;
	char	**expanded;
	char	*spaced_line;

	spaced_line = space_line(line);
	tokens = ft_split_quotes(spaced_line, ' ');
	free(spaced_line);
	if (!tokens)
	{
		ft_printf("split line failed");
		free(line);
		exit(1);
	}
	expanded = expand_vars(tokens, shell);
	free_arr(tokens);
	tokens = expanded;
	return (tokens);
}
