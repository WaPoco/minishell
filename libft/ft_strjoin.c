/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmote <hmote@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 11:19:43 by hmote             #+#    #+#             */
/*   Updated: 2025/04/08 22:29:25 by hmote            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	target_size;
	char	*new_str;

	if (!s1 || !s2)
		return (NULL);
	target_size = ft_strlen(s1) + ft_strlen(s2) + 1;
	new_str = malloc(target_size * sizeof(char));
	if (!new_str)
		return (NULL);
	if (s1)
		ft_strlcpy(new_str, s1, ft_strlen(s1) + 1);
	else
		new_str[0] = '\0';
	if (s2)
		ft_strlcat(new_str, s2, target_size);
	return (new_str);
}
