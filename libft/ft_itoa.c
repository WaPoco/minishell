/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmote <hmote@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 18:14:05 by hmote             #+#    #+#             */
/*   Updated: 2025/04/08 22:28:35 by hmote            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int	counter(int n)
{
	int	count;

	count = (n <= 0);
	while (n != 0)
	{
		n = n / 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	char	*s;
	int		count;
	long	num;

	num = n;
	count = counter(num);
	s = (char *)malloc((count + 1) * sizeof(char));
	if (!s)
		return (NULL);
	s[count] = '\0';
	if (num < 0)
	{
		s[0] = '-';
		num = -num; 
	}
	while (count-- > 0)
	{
		s[count] = (num % 10) + '0';
		num /= 10;
	}
	return (s);
}
