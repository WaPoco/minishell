/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpogorel <vpogorel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 19:52:45 by hmote             #+#    #+#             */
/*   Updated: 2025/07/25 13:23:31 by vpogorel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <unistd.h>
# include <stdlib.h>
# include "libft.h"
# include <signal.h>
# include <sys/wait.h>
# include <fcntl.h>
# include <errno.h>
# include <sys/stat.h>

typedef struct s_shell
{
	char	**env;
	int		stdin_save;
	int		stdout_save;
	int		should_exit;
}	t_shell;

typedef struct s_redirect
{
	int		in;
	int		out;
	char	*infile;
	char	*outfile;
	int		append;
	int		heredoc;
	char	*delimiter;
}	t_redirect;

extern int	g_sigint;

void	init_shell(t_shell *shell, char **envp);
void	setup_signals(void);

// builtin funcs
int		builtin_echo(char **args);
int		builtin_pwd(void);
int		builtin_cd(t_shell *shell, char **args);
int		builtin_env(char **env);
int		builtin_export(t_shell *shell, char **args);
int		builtin_unset(t_shell *shell, char **args);
int		builtin_exit(t_shell *shell, char **args);

// execute funcs
int		is_builtin(char *cmd);
int		execute_builtin(t_shell *shell, char **args);
void	execute_external(t_shell *shell, char **args);
// int		execute(t_shell *shell, char *line);
char	**tokenize(char *line, t_shell *shell);
void	parse_and_execute(t_shell *shell, char *line);
char	**expand_vars(char **tokens, t_shell *shell);
int		execute_pipeline(t_shell *shell, char *line);
//void	exec_command(t_shell *shell, char **args);

// execute tools
void	compact_args(char **args);
int		is_literal(const char *line, char c);
int		is_directory(const char *path);
int		is_executable(char *path);

// Helpers
char	*get_env_value(char **env, const char *var);
int		set_env_var(t_shell *shell, const char *var, const char *value);
char	**update_env(char ***env, int env_size, char *new_var);
char	*make_full_path(const char *path, const char *cmd);
void	execute_fork(t_shell *shell, char **args, int *status);

// Helpers expand line
void	update_result(char **result);
void	append_char(char **result, char c);
void	handle_var(const char *token, char **result,
			t_shell *shell, int *i);
void	handle_dollar(const char *token, char **result,
			t_shell *shell, int *i);

// pipe tools
void	setup_fds(char **cmds, int i, int *fds);
int		wait_all_children(int count, pid_t *pids);

// Utilities
void	free_arr(char **arr);
char	**copy_arr(char **arr);
void	print_arr(char **arr);
int		ft_arrlen(char **arr);
char	**ft_split_quotes(const char *str, char c);
void	ft_qsort(char **arr, int start, int end);
int		is_quoted(int index, const char *s);

// Redirections
int		handle_redirections(char **args, t_redirect *redir);
int		apply_redirections(t_redirect *redir, t_shell *shell);
void	reset_std_fds(t_shell *shell);
void	free_redirection(t_redirect *redir);

#endif
