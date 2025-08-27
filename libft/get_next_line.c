/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmote <hmote@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 10:12:01 by hmote             #+#    #+#             */
/*   Updated: 2025/04/08 22:30:04 by hmote            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
#ifndef BUFFER_SIZE
# define BUFFER_SIZE 1
#endif

char	*update_leftover(char **leftover)
{
	char	*rest;
	int		i;
	int		j;

	if (!ft_strchr(*leftover, '\n'))
	{
		free(*leftover);
		*leftover = NULL;
		return (NULL);
	}
	i = 0;
	while ((*leftover)[i] != '\n')
		i++;
	rest = (char *)malloc(ft_strlen(*leftover) - i);
	if (!rest)
		return (NULL);
	i++;
	j = 0;
	while ((*leftover)[i])
		rest[j++] = (*leftover)[i++];
	rest[j] = '\0';
	free(*leftover);
	*leftover = rest;
	return (*leftover);
}

char	*extract_line(char *s)
{
	size_t	i;
	char	*line;

	if (!s || !*s)
		return (NULL);
	i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	line = (char *)malloc(i + 2);
	if (!line)
		return (NULL);
	i = 0;
	while (s[i] && s[i] != '\n')
	{
		line[i] = s[i];
		i++;
	}
	if (s[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*append(char **leftover, const char *s2)
{
	char	*temp;
	int		i;
	int		j;

	if (!*leftover)
		return (NULL);
	temp = (char *)malloc(ft_strlen(*leftover) + ft_strlen(s2) + 1);
	if (!temp)
		return (NULL);
	i = 0;
	j = 0;
	while ((*leftover)[i])
	{
		temp[i] = (*leftover)[i];
		i++;
	}
	while (s2[j])
		temp[i++] = s2[j++];
	temp[i] = '\0';
	free(*leftover);
	*leftover = temp;
	return (*leftover);
}

char	*read_file(int fd, char *buffer, char **leftover)
{
	ssize_t	bytes_read;

	if (!*leftover)
		*leftover = ft_strdup("");
	while (!ft_strchr(*leftover, '\n'))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
		{
			free(buffer);
			free(*leftover);
			*leftover = NULL;
			return (NULL);
		}
		if (bytes_read == 0)
			break ;
		buffer[bytes_read] = '\0';
		append(leftover, buffer);
	}
	return (buffer);
}

char	*get_next_line(int fd)
{
	char			*buffer;
	static char		*leftover;
	char			*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = (char *)malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	buffer = read_file(fd, buffer, &leftover);
	free(buffer);
	line = extract_line(leftover);
	update_leftover(&leftover);
	return (line);
}
