/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmote <hmote@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 15:36:42 by hmote             #+#    #+#             */
/*   Updated: 2025/04/08 22:27:06 by hmote            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

static int	ft_isspace(int c)
{
	return (c == 32 || (c >= 9 && c <= 13));
}

int	ft_atoi(const char *nptr)
{
	int	i;
	int	sign;
	int	converted_value;

	i = 0;
	while (ft_isspace(nptr[i]))
	{
		i++;
	}
	sign = 1;
	converted_value = 0;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			sign = -sign;
		i++;
	}
	while (ft_isdigit(nptr[i]))
	{
		converted_value = (converted_value * 10) + (nptr[i] - 48);
		i++;
	}
	return (converted_value * sign);
}
