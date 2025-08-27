/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpogorel <vpogorel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 18:31:56 by hmote             #+#    #+#             */
/*   Updated: 2025/07/25 13:32:08 by vpogorel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	g_sigint = 0;

/**
 * Handler for SIGINT (Ctrl+C)
 * Writes a newline and redisplays prompt
 * I assign the global var to the SIGINT
 *  (ctrl + D) because I want to 
 * check it later in another file. 
 * for what? (e.g. to cancel commands) 
 */
static void	handle_sigint(int sig)
{
	(void)sig;
	g_sigint = SIGINT;
	write(1, "\n", 1);
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
}

/**
 * Handler for SIGQUIT (Ctrl+\)
 * Does nothing (like bash) in the parent procees
 *  Warning: should we write "Quit (core dumped)" in the child processes?
 */
static void	handle_sigquit(int sig)
{
	(void)sig;
}

void	setup_signals(void)
{
	signal(SIGINT, handle_sigint);
	signal(SIGQUIT, handle_sigquit);
}
