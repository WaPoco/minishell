/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpogorel <vpogorel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 19:50:41 by hmote             #+#    #+#             */
/*   Updated: 2025/07/25 13:12:12 by vpogorel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/minishell.h"

// check whether add_history persist the history when the program restarts?
	// It doesn't! should be kept?

static int	check_heredoc(char *line)
{
	int	i;

	i = 0;
	while (line[i] != '\0')
	{
		if (line[i] == '<' && line[i + 1] == '<')
			return (1);
		i++;
	}
	return (0);
}

void	clean_up(t_shell *shell)
{
	rl_clear_history();
	free_arr(shell->env);
	reset_std_fds(shell);
}

int	main(int argc, char **argv, char **envp)
{
	char	*line;
	t_shell	shell;

	(void)argc;
	(void)argv;
	init_shell(&shell, envp);
	while (!shell.should_exit)
	{
		setup_signals();
		line = readline("minishel$ ");
		if (!line)
		{
			write(1, "exit\n", 5);
			break ;
		}
		if (*line)
		{
			if (!check_heredoc(line))
				add_history(line);
			parse_and_execute(&shell, line);
		}
		free(line);
	}
	clean_up(&shell);
	exit(g_sigint);
}
