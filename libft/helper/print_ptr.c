/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmote <hmote@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 11:58:37 by hmote             #+#    #+#             */
/*   Updated: 2025/04/08 22:31:51 by hmote            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

size_t	print_ptr(void *ptr)
{
	size_t			len;
	unsigned long	address;

	len = 0;
	if (ptr == NULL)
	{
		ft_putstr_fd("(nil)", 1);
		return (5);
	}
	ft_putstr_fd("0x", 1);
	len += 2;
	address = (unsigned long)ptr;
	len += print_hex(address, 0);
	return (len);
}
