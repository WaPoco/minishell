/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpogorel <vpogorel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 16:07:12 by hmote             #+#    #+#             */
/*   Updated: 2025/07/24 19:31:56 by vpogorel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"
/**
 * Parses args to extract redirection info and remove them from args.
 */
void	free_redirection(t_redirect *redir)
{
	if (redir->delimiter)
		free(redir->delimiter);
	if (redir->infile)
		free(redir->infile);
	if (redir->outfile)
		free(redir->outfile);
}

static int	handle_output(char **args, t_redirect *redir, int *i)
{
	if (ft_strcmp(args[*i], ">") == 0 && args[*i + 1])
	{
		if (redir->outfile)
			free(redir->outfile);
		redir->outfile = ft_strdup(args[*i + 1]);
		free(args[*i + 1]);
		free(args[*i]);
		redir->append = 0;
		*i += 2;
		return (1);
	}
	if (ft_strcmp(args[*i], ">>") == 0 && args[*i + 1])
	{
		if (redir->outfile)
			free(redir->outfile);
		redir->outfile = ft_strdup(args[*i + 1]);
		redir->append = 1;
		free(args[*i + 1]);
		free(args[*i]);
		*i += 2;
		return (1);
	}
	return (0);
}

static int	handle_input(char **args, t_redirect *redir, int *i)
{
	if (ft_strcmp(args[*i], "<") == 0 && args[*i + 1])
	{
		if (redir->infile)
			free(redir->infile);
		redir->infile = ft_strdup(args[*i + 1]);
		free(args[*i + 1]);
		free(args[*i]);
		*i += 2;
		return (1);
	}
	if (ft_strcmp(args[*i], "<<") == 0 && args[*i + 1])
	{
		redir->heredoc = 1;
		if (redir->delimiter)
			free(redir->delimiter);
		redir->delimiter = ft_strdup(args[*i + 1]);
		free(args[*i + 1]);
		free(args[*i]);
		*i += 2;
		return (1);
	}
	return (0);
}

int	handle_redirections(char **args, t_redirect *redir)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	redir->in = -1;
	redir->out = -1;
	redir->append = 0;
	redir->infile = NULL;
	redir->outfile = NULL;
	redir->delimiter = NULL;
	redir->heredoc = 0;
	while (args[i])
	{
		if (handle_output(args, redir, &i))
			continue ;
		if (handle_input(args, redir, &i))
			continue ;
		args[j++] = args[i++];
	}
	args[j] = NULL;
	return (0);
}
