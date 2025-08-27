/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_external.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpogorel <vpogorel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 20:03:36 by hmote             #+#    #+#             */
/*   Updated: 2025/07/25 13:33:04 by vpogorel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

/**
 *	Goal: To check if the file at the path* exists and is executable by the user
 *	path comes from the environment variables (env) already saved in shell->env
 * - using stat() is allowed by the subject 
	Commands like ls, echo and cat are executable files in the path adresses 
	They are ecxecuted using exceve() witch is allowed by the subject
	
	A good practice: we can make this func and the make_new_env_var() one func and
	place it in the helpers and make it reusable
*/

char	*search_in_path(char *cmd, char *path)
{
	char	**paths;
	char	*full;
	int		i;

	if (!path)
		return (NULL);
	paths = ft_split(path, ':');
	if (!paths)
		return (NULL);
	i = 0;
	while (paths[i])
	{
		full = make_full_path(paths[i], cmd);
		if (is_executable(full))
		{
			free_arr(paths);
			return (full);
		}
		free(full);
		i++;
	}
	free_arr(paths);
	return (NULL);
}

char	*find_command(char *cmd, char **env)
{
	char	*path;
	char	*full_path;

	if (ft_strchr(cmd, '/'))
	{
		if (is_executable(cmd))
			return (ft_strdup(cmd));
		else
			return (NULL);
	}
	path = get_env_value(env, "PATH");
	full_path = search_in_path(cmd, path);
	if (!full_path)
		return (NULL);
	return (full_path);
}

static void	external_error(char *cmd, char *msg, int code, t_shell *shell)
{
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd(cmd, 2);
	ft_putstr_fd(msg, 2);
	reset_std_fds(shell);
	exit(code);
}

static void	handle_execve_error(char *cmd, t_shell *shell)
{
	if (errno == EACCES)
		external_error(cmd, ": Permission denied\n", 126, shell);
	else if (errno == ENOENT)
		external_error(cmd, ": No such file or directory\n", 127, shell);
	else if (errno == EISDIR)
		external_error(cmd, ": Is a directory\n", 126, shell);
	else
	{
		perror("minishell");
		reset_std_fds(shell);
		exit(1);
	}
}

void	execute_external(t_shell *shell, char **args)
{
	char	*cmd_path;

	if (ft_strchr(args[0], '/'))
	{
		if (is_directory(args[0]))
			external_error(args[0], ": Is a directory\n", 126, shell);
		if (execve(args[0], args, shell->env) == -1)
			handle_execve_error(args[0], shell);
		return ;
	}
	cmd_path = find_command(args[0], shell->env);
	if (!cmd_path)
		external_error(args[0], ": command not found\n", 127, shell);
	if (is_directory(cmd_path))
		external_error(cmd_path, ": Is a directory\n", 126, shell);
	execve(cmd_path, args, shell->env);
	free(cmd_path);
	reset_std_fds(shell);
	if (errno == EACCES)
		exit(126);
	perror("minishell");
	exit(127);
}
