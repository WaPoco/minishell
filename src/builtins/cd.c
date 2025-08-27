/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmote <hmote@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 22:06:55 by hmote             #+#    #+#             */
/*   Updated: 2025/04/17 23:33:29 by hmote            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

/**
 * To updates PWD and OLDPWD in the environment
 * (env struct we made it in the init shell copied from envp)
 * type "env" in the shell terminal to see vars and values
 */

static void	update_pwd(t_shell *shell, const char *oldpwd)
{
	char	*cwd;

	cwd = getcwd(NULL, 0);
	if (!cwd)
	{
		perror("minishell: cd");
		return ;
	}
	set_env_var(shell, "OLDPWD", oldpwd);
	set_env_var(shell, "PWD", cwd);
	free(cwd);
}

static int	cd_error(char *msg, char *oldpwd)
{
	write(2, msg, ft_strlen(msg));
	if (oldpwd)
		free(oldpwd);
	return (1);
}

static char	*cd_handle_oldpwd(t_shell *shell, char *oldpwd)
{
	char	*path;

	path = get_env_value(shell->env, "OLDPWD");
	if (!path)
	{
		cd_error("minishell: cd: OLDPWD not set\n", oldpwd);
		return (NULL);
	}
	printf("%s\n", path);
	return (path);
}

int	builtin_cd(t_shell *shell, char **args)
{
	char	*path;
	char	*oldpwd;

	oldpwd = getcwd(NULL, 0);
	if (!oldpwd)
		return (cd_error("minishell: cd: error retrieving cwd\n", NULL));
	if (args[1] && args[2])
		return (cd_error("minishell: cd: too many arguments\n", oldpwd));
	if (!args[1])
		path = get_env_value(shell->env, "HOME");
	else if (ft_strcmp(args[1], "-") == 0)
		path = cd_handle_oldpwd(shell, oldpwd);
	else
		path = args[1];
	if (!path || chdir(path) != 0)
	{
		if (!path)
			return (cd_error("minishell: cd: path not set\n", oldpwd));
		perror("minishell: cd");
		free(oldpwd);
		return (1);
	}
	update_pwd(shell, oldpwd);
	free(oldpwd);
	return (0);
}
