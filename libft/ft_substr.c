/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmote <hmote@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 20:19:49 by hmote             #+#    #+#             */
/*   Updated: 2025/04/08 22:29:55 by hmote            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substring;

	if (!s || start >= ft_strlen(s) || !len)
		return (ft_strdup(""));
	if (len > ft_strlen(s) - start)
	{
		len = ft_strlen(s) - start;
	}
	substring = (char *)malloc((len + 1) * sizeof(char));
	if (!substring)
	{
		return (NULL);
	}
	ft_strlcpy(substring, s + start, len + 1);
	return (substring);
}
