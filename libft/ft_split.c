/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmote <hmote@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 18:06:37 by hmote             #+#    #+#             */
/*   Updated: 2025/07/20 13:11:45 by hmote            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

static int	count_words(const char *s, char c)
{
	int	count;
	int	flag;

	count = 0;
	flag = 0;
	while (*s)
	{
		if (*s != c && flag == 0)
		{
			count++;
			flag = 1;
		}
		else if (*s == c)
			flag = 0;
		s++;
	}
	return (count);
}

static char	*get_next_word(const char **str, char c)
{
	int		len;
	char	*start;
	char	*word;
	int		i;

	start = (char *)*str;
	while (*start == c)
		start++;
	len = 0;
	while (start[len])
	{
		if (start[len] == c)
			break ;
		len++;
	}
	word = malloc(len + 1);
	if (!word)
		return (NULL);
	i = -1;
	while (++i < len)
		word[i] = start[i];
	word[i] = '\0';
	*str = start + len;
	return (word);
}

char	**ft_split(const char *str, char c)
{
	char	**arr;
	int		words;
	char	*word;
	int		i;

	words = count_words(str, c);
	arr = malloc((words + 1) * sizeof(char *));
	if (!arr)
		return (NULL);
	i = -1;
	while (++i < words)
	{
		word = get_next_word(&str, c);
		arr[i] = word;
		if (!arr[i])
		{
			while (i-- > 0)
				free(arr[i]);
			free(arr);
			return (NULL);
		}
	}
	arr[i] = NULL;
	return (arr);
}
