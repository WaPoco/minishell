/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_shell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpogorel <vpogorel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 20:25:15 by hmote             #+#    #+#             */
/*   Updated: 2025/07/25 13:12:57 by vpogorel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	check_for_oldpwd(t_shell *shell)
{
	char	*oldpwd;
	char	*cwd;

	oldpwd = get_env_value(shell->env, "OLDPWD");
	if (!oldpwd)
	{
		cwd = getcwd(NULL, 0);
		if (cwd)
		{
			set_env_var(shell, "OLDPWD", cwd);
			free(cwd);
		}
	}
}

void	init_shell(t_shell *shell, char **envp)
{
	rl_catch_signals = 0;
	shell->env = copy_arr(envp);
	if (!shell->env)
	{
		perror("minishell: env allocation failed!");
		exit(1);
	}
	shell->should_exit = 0;
	shell->stdin_save = -1;
	shell->stdout_save = -1;
	check_for_oldpwd(shell);
}
