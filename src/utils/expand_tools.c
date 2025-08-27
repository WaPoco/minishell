/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_tools.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpogorel <vpogorel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 16:44:54 by vpogorel          #+#    #+#             */
/*   Updated: 2025/07/25 13:22:09 by vpogorel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	update_result(char **result)
{
	char	*code;
	char	*tmp;

	code = ft_itoa(g_sigint);
	tmp = ft_strjoin(*result, code);
	free(*result);
	free(code);
	*result = tmp;
}

void	append_char(char **result, char c)
{
	char	tmp[2];
	char	*joined;

	tmp[0] = c;
	tmp[1] = '\0';
	joined = ft_strjoin(*result, tmp);
	free(*result);
	*result = joined;
}

void	handle_var(const char *token, char **result,
	t_shell *shell, int *i)
{
	int		start;
	char	*name;
	char	*val;
	char	*tmp;

	start = *i;
	while (token[*i] && (ft_isalnum(token[*i]) || token[*i] == '_'))
		(*i)++;
	name = ft_substr(&token[start], 0, *i - start);
	val = get_env_value(shell->env, name);
	free(name);
	if (val)
	{
		tmp = ft_strjoin(*result, val);
		free(*result);
		*result = tmp;
	}
}

void	handle_dollar(const char *token, char **result,
	t_shell *shell, int *i)
{
	if (token[*i] == '\0')
		append_char(result, '$');
	else if (token[*i] == '?')
	{
		update_result(result);
		(*i)++;
	}
	else if (ft_isalpha(token[*i]) || token[*i] == '_')
		handle_var(token, result, shell, i);
	else
		append_char(result, '$');
}
