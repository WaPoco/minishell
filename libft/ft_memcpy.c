/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmote <hmote@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 10:54:18 by hmote             #+#    #+#             */
/*   Updated: 2025/04/08 22:28:44 by hmote            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;
	char	*src_ptr;
	char	*dest_ptr;

	if (!dest && !src)
	{
		return (NULL);
	}
	i = 0;
	src_ptr = (char *)src;
	dest_ptr = (char *)dest;
	while (i < n)
	{
		dest_ptr[i] = src_ptr[i];
		i++;
	}
	return (dest);
}
