/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_un_num.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmote <hmote@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 12:23:29 by hmote             #+#    #+#             */
/*   Updated: 2025/04/08 22:32:01 by hmote            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

size_t	print_un_num(unsigned int num)
{
	int	i;

	if (num == 0)
	{
		ft_putchar_fd('0', 1);
		return (1);
	}
	i = 0;
	ft_putunnbr_fd(num, 1);
	while (num > 0)
	{
		i++;
		num /= 10;
	}
	return (i);
}
