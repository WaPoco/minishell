/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpogorel <vpogorel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 00:18:52 by hmote             #+#    #+#             */
/*   Updated: 2025/07/25 13:30:34 by vpogorel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	free_arr(char **arr)
{
	int	i;

	i = 0;
	if (!arr)
		return ;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

char	**copy_arr(char **arr)
{
	int		members;
	char	**copy;
	int		i;

	members = 0;
	while (arr[members])
		members++;
	copy = malloc(sizeof(char *) * (members + 1));
	if (!copy)
		return (NULL);
	i = 0;
	while (i < members)
	{
		copy[i] = ft_strdup(arr[i]);
		i++;
	}
	copy[members] = NULL;
	return (copy);
}

void	print_arr(char **arr)
{
	int	i;

	i = 0;
	while (arr && arr[i])
	{
		write(1, arr[i], ft_strlen(arr[i]));
		write(1, "\n", 1);
		i++;
	}
}

int	ft_arrlen(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		i++;
	return (i);
}
