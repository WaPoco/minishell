/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmote <hmote@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 15:27:03 by hmote             #+#    #+#             */
/*   Updated: 2025/04/08 22:28:59 by hmote            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	int	result;

	if (!s || fd < 0)
	{
		write(2, "Error: Invalid input\n", 21);
		return ;
	}
	result = write(fd, s, ft_strlen(s));
	if (result == -1)
	{
		write(2, "Error: Unable to write string\n", 30);
	}
	result = write(fd, "\n", 1);
	if (result == -1)
	{
		write(2, "Error: Unable to write newline\n", 31);
	}
}
