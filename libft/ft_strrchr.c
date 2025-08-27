/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmote <hmote@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 21:29:57 by hmote             #+#    #+#             */
/*   Updated: 2025/04/08 22:29:49 by hmote            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*last_c;

	last_c = NULL;
	while (*s != '\0')
	{
		if (*s == (unsigned char)c)
			last_c = ((char *) s);
		s++;
	}
	if ((unsigned char)c == '\0')
		return ((char *)s);
	return (last_c);
}
