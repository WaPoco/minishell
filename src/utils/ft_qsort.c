/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_qsort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmote <hmote@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 12:49:07 by hmote             #+#    #+#             */
/*   Updated: 2025/07/16 15:05:10 by hmote            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	ft_swap(char **a, char **b)
{
	char	*tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

int	ft_partition(char **arr, int l, int r)
{
	int		i;
	int		j;
	char	*pivot;

	i = l;
	j = l;
	pivot = arr[r];
	while (i < r)
	{
		if (ft_strcmp(arr[i], pivot) < 0)
		{
			ft_swap(&arr[j], &arr[i]);
			j++;
		}
		i++;
	}
	ft_swap(&arr[j], &arr[i]);
	return (j);
}

void	ft_qsort(char **arr, int start, int end)
{
	int	pivot_i;

	if (start < end)
	{
		pivot_i = ft_partition(arr, start, end);
		ft_qsort(arr, start, pivot_i - 1);
		ft_qsort(arr, pivot_i + 1, end);
	}
}
