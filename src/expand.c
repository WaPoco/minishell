/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpogorel <vpogorel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 16:30:48 by hmote             #+#    #+#             */
/*   Updated: 2025/07/25 13:22:31 by vpogorel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
* Expands all variables in tokens (except single-quoted)
*/

#include "../include/minishell.h"

static void	process_token_loop(const char *token, char **result,
	t_shell *shell)
{
	int	i;
	int	in_single;
	int	in_double;

	i = 0;
	in_single = 0;
	in_double = 0;
	while (token[i])
	{
		if (token[i] == '\'' && !in_double)
			in_single = !in_single;
		else if (token[i] == '"' && !in_single)
			in_double = !in_double;
		else if (token[i] == '$' && !in_single)
		{
			i++;
			handle_dollar(token, result, shell, &i);
			continue ;
		}
		else
			append_char(result, token[i]);
		if (token[i])
			i++;
	}
}

static char	*expand_token(const char *token, t_shell *shell)
{
	char	*result;

	result = ft_strdup("");
	process_token_loop(token, &result, shell);
	return (result);
}

char	**expand_vars(char **tokens, t_shell *shell)
{
	int		count;
	int		i;
	char	**new;

	count = 0;
	while (tokens[count])
		count++;
	new = malloc(sizeof(char *) * (count + 1));
	if (!new)
		return (NULL);
	i = 0;
	while (i < count)
	{
		new[i] = expand_token(tokens[i], shell);
		if (!new[i])
			new[i] = ft_strdup("");
		i++;
	}
	new[count] = NULL;
	return (new);
}
