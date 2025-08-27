/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmote <hmote@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 09:47:41 by hmote             #+#    #+#             */
/*   Updated: 2025/07/16 15:08:19 by hmote            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

/* 
	Tip:	export -- shows all exported variables (alphabethically sorted),
	even if they have no value yet
			and shows unset exported vars
		vs.
			env -- shows only variables that are currently set with a value
			and doesn't show unset exported vars

	Next steps:
		1-	print_export should sort the array first and then print it
			for this purpose we can use reproduced version of "qsort" and
			add to our libft library
			and then printing the sorted array behaved likewise
			the original Shell does 
		
		2-	we might consider handling input like:
			export VAR="value with spaces"
*/

static void	print_export(char **env)
{
	char	**sorted_array;

	sorted_array = copy_arr(env);
	ft_qsort(sorted_array, 0, ft_arrlen(env) - 1);
	print_arr(sorted_array);
	free_arr(sorted_array);
}

int	is_valid_identifier(const char *s)
{
	int	i;

	i = 0;
	if (!s || (!ft_isalpha(s[0]) && s[0] != '_'))
	{
		return (0);
	}
	while (s[i])
	{
		if (!ft_isalnum(s[i]) && s[i] != '_')
		{
			return (0);
		}
		i++;
	}
	return (1);
}

static int	export_error(char *arg)
{
	ft_putstr_fd("minishell: export: `", 2);
	ft_putstr_fd(arg, 2);
	ft_putstr_fd("': not a valid identifier\n", 2);
	return (1);
}

int	builtin_export(t_shell *shell, char **args)
{
	int		i;
	char	*eq;

	if (!args[1])
	{
		print_export(shell->env);
		return (0);
	}
	i = 0;
	while (args[++i])
	{
		eq = ft_strchr(args[i], '=');
		if (eq)
			*eq = '\0';
		if (!is_valid_identifier(args[i]))
			return (export_error(args[i]));
		if (eq)
		{
			set_env_var(shell, args[i], eq + 1);
			*eq = '=';
		}
		else
			set_env_var(shell, args[i], "");
	}
	return (0);
}
