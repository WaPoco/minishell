/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunnbr_fd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmote <hmote@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 15:42:10 by hmote             #+#    #+#             */
/*   Updated: 2025/04/08 22:31:23 by hmote            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

void	ft_putunnbr_fd(unsigned int n, int fd)
{
	char	c;

	if (n >= 10)
	{
		ft_putunnbr_fd(n / 10, fd);
	}
	c = n % 10 + '0';
	ft_putchar_fd(c, fd);
}
