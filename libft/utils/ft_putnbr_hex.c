/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmote <hmote@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 18:19:34 by hmote             #+#    #+#             */
/*   Updated: 2025/04/08 22:31:20 by hmote            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

void	ft_putnbr_hex(unsigned long n, int uppercase)
{
	char	*hex_digits;
	char	digit;

	if (uppercase)
		hex_digits = "0123456789ABCDEF";
	else
		hex_digits = "0123456789abcdef";
	if (n >= 16)
		ft_putnbr_hex(n / 16, uppercase);
	digit = hex_digits[n % 16];
	write(1, &digit, 1);
}
