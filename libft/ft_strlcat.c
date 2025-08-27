/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmote <hmote@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 13:20:11 by hmote             #+#    #+#             */
/*   Updated: 2025/04/08 22:29:28 by hmote            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dest_len;
	size_t	i;
	size_t	src_len;

	dest_len = ft_strlen(dst);
	i = 0;
	src_len = ft_strlen(src);
	if (size <= dest_len)
		return (size + src_len);
	while (i < (size - dest_len - 1) && src[i] != '\0')
	{
		dst[dest_len + i] = src[i];
		i++;
	}
	dst[dest_len + i] = '\0';
	return (dest_len + src_len);
}
