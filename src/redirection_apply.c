/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection_apply.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpogorel <vpogorel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 19:29:40 by vpogorel          #+#    #+#             */
/*   Updated: 2025/07/25 13:28:45 by vpogorel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * Opens and applies redirections with dup2
 */

#include "minishell.h"

int	handle_heredoc(t_redirect *redir, t_shell *shell)
{
	int		pipe_fd[2];
	char	*line;

	if (pipe(pipe_fd) == -1)
	{
		perror("minishell: heredoc pipe");
		reset_std_fds(shell);
		return (1);
	}
	while (1)
	{
		line = readline("> ");
		if (!line || ft_strcmp(line, redir->delimiter) == 0)
		{
			free(line);
			reset_std_fds(shell);
			break ;
		}
		write(pipe_fd[1], line, ft_strlen(line));
		write(pipe_fd[1], "\n", 1);
		free(line);
	}
	close(pipe_fd[1]);
	redir->in = pipe_fd[0];
	return (0);
}

int	open_infile(t_redirect *redir, t_shell *shell)
{
	(void)shell;
	redir->in = open(redir->infile, O_RDONLY);
	if (redir->in < 0)
	{
		perror("minishell: input file");
		reset_std_fds(shell);
		g_sigint = 1;
		return (1);
	}
	return (0);
}

int	open_outfile(t_redirect *redir, t_shell *shell)
{
	int	flags;

	(void)shell;
	flags = O_CREAT | O_WRONLY;
	if (redir->append)
		flags |= O_APPEND;
	else
		flags |= O_TRUNC;
	redir->out = open(redir->outfile, flags, 0644);
	if (redir->out < 0)
	{
		perror("minishell: output file");
		reset_std_fds(shell);
		g_sigint = 1;
		return (1);
	}
	return (0);
}

int	apply_redirections(t_redirect *redir, t_shell *shell)
{
	if (redir->heredoc && handle_heredoc(redir, shell))
		return (1);
	if (redir->infile && open_infile(redir, shell))
		return (1);
	if (redir->in >= 0)
	{
		if (dup2(redir->in, STDIN_FILENO) == -1)
			return (perror("dup2"), 1);
		close(redir->in);
	}
	if (redir->outfile && open_outfile(redir, shell))
		return (1);
	if (redir->out >= 0)
	{
		if (dup2(redir->out, STDOUT_FILENO) == -1)
			return (perror("dup2"), 1);
		close(redir->out);
	}
	return (0);
}
