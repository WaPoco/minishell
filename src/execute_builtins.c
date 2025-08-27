/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_builtins.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmote <hmote@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 20:00:17 by hmote             #+#    #+#             */
/*   Updated: 2025/07/18 18:39:48 by hmote            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

/* 
	What it does: It invokes coresponded func in different cases.
	It return what the builin funcs return_ 1 in eror and 0 in succss
	because it is implied in the "parse_and_execute" and at the end in the "main"
			

	Hint: dont forget to delete the debuger line

	To Do:	Don't forget to modify echo to return an int (1 or 0)
			dont forget to delete the debuger line

*/

int	execute_builtin(t_shell *shell, char **args)
{
	if (ft_strcmp(args[0], "echo") == 0)
		return (builtin_echo(args));
	else if (ft_strcmp(args[0], "pwd") == 0)
		return (builtin_pwd());
	else if (ft_strcmp(args[0], "cd") == 0)
		return (builtin_cd(shell, args));
	else if (ft_strcmp(args[0], "env") == 0)
		return (builtin_env(shell->env));
	else if (ft_strcmp(args[0], "export") == 0)
		return (builtin_export(shell, args));
	else if (ft_strcmp(args[0], "unset") == 0)
		return (builtin_unset(shell, args));
	else if (ft_strcmp(args[0], "exit") == 0)
		return (builtin_exit(shell, args));
	return (0);
}
