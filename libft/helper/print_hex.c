/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmote <hmote@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 12:51:55 by hmote             #+#    #+#             */
/*   Updated: 2025/04/08 22:31:41 by hmote            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

size_t	print_hex(unsigned long hex_num, int uppercase)
{
	size_t	i;

	if (hex_num == 0)
	{
		ft_putchar_fd('0', 1);
		return (1);
	}
	i = 0;
	ft_putnbr_hex(hex_num, uppercase);
	while (hex_num > 0)
	{
		hex_num /= 16;
		i++;
	}
	return (i);
}
