/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmote <hmote@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 22:12:06 by hmote             #+#    #+#             */
/*   Updated: 2025/04/19 19:15:14 by hmote            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// src/env.c

#include "../include/minishell.h"

// To get the value of an environment var, or NULL if not found
// however it was allowed to use "getenv" as an external func; anyway
char	*get_env_value(char **env, const char *var)
{
	int		i;
	size_t	var_len;

	i = 0;
	var_len = ft_strlen(var);
	while (env[i])
	{
		if (ft_strncmp(env[i], var, var_len) == 0 && env[i][var_len] == '=')
			return (env[i] + var_len + 1);
		i++;
	}
	return (NULL);
}

char	**update_env(char ***env, int env_size, char *new_var)
{
	char	**new_env;
	int		i;

	new_env = malloc(sizeof(char *) * (env_size + 2));
	if (!new_env)
		return (NULL);
	i = 0;
	while (i < env_size)
	{
		new_env[i] = (*env)[i];
		i++;
	}
	new_env[i] = new_var;
	new_env[i + 1] = NULL;
	free(*env);
	return (new_env);
}

// To make a new string wich is concatination of var and value
static char	*make_new_env_member(const char *var, const char *value)
{
	size_t	var_len;
	size_t	value_len;
	char	*new_mem;

	var_len = ft_strlen(var);
	value_len = ft_strlen(value);
	new_mem = malloc(var_len + value_len + 2);
	if (!new_mem)
		return (NULL);
	ft_memcpy(new_mem, var, var_len);
	new_mem[var_len] = '=';
	ft_memcpy(new_mem + var_len + 1, value, value_len);
	new_mem[var_len + value_len + 1] = '\0';
	return (new_mem);
}

// To set or replace an environment var in shell->env if Not found: add new var
int	set_env_var(t_shell *shell, const char *var, const char *value)
{
	int		i;
	char	*new_mem;
	char	**env;

	i = 0;
	env = shell->env;
	new_mem = make_new_env_member(var, value);
	if (!new_mem)
		return (1);
	while (env[i])
	{
		if (ft_strncmp(env[i], var, ft_strlen(var)) == 0
			&& env[i][ft_strlen(var)] == '=')
		{
			free(env[i]);
			env[i] = new_mem;
			return (0);
		}
		i++;
	}
	shell->env = update_env(&env, i, new_mem);
	return (0);
}
