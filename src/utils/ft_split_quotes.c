/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_quotes.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpogorel <vpogorel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 18:06:37 by hmote             #+#    #+#             */
/*   Updated: 2025/07/25 13:45:58 by vpogorel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static int	count_words(const char *s, char c)
{
	int			count;
	int			flag;
	int			index;
	const char	*sc;

	count = 0;
	flag = 0;
	index = 0;
	sc = s;
	while (*s)
	{
		if (*s != c && flag == 0)
		{
			count++;
			flag = 1;
		}
		else if (*s == c && !is_quoted(index, sc))
			flag = 0;
		s++;
		index++;
	}
	return (count);
}

static int	get_word_len(const char *start, char c, const char *full, int idx)
{
	int	len;

	len = 0;
	while (start[len])
	{
		if (start[len] == c && !is_quoted(idx, full))
			break ;
		len++;
		idx++;
	}
	return (len);
}

static char	*copy_word(const char *start, int len)
{
	char	*word;
	int		i;

	word = malloc(len + 1);
	if (!word)
		return (NULL);
	i = -1;
	while (++i < len)
		word[i] = start[i];
	word[i] = '\0';
	return (word);
}

static char	*get_next_word(const char **str, char c)
{
	int		index;
	int		len;
	char	*start;
	char	*word;

	index = 0;
	start = (char *)*str;
	while (*start == c)
	{
		start++;
		index++;
	}
	len = get_word_len(start, c, *str, index);
	word = copy_word(start, len);
	if (!word)
		return (NULL);
	*str = start + len;
	return (word);
}

char	**ft_split_quotes(const char *str, char c)
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
