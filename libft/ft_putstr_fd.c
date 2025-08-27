/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmote <hmote@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 15:08:02 by hmote             #+#    #+#             */
/*   Updated: 2025/04/08 22:29:05 by hmote            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	if (!s || fd < 0)
	{
		write(2, "Error: Invalid input\n", 21);
		return ;
	}
	if (write(fd, s, ft_strlen(s)) == -1)
	{
		write(2, "Error: Unable to write string\n", 30);
	}
}
