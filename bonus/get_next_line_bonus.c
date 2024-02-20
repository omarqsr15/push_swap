/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-qasr <oel-qasr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 22:55:36 by oel-qasr          #+#    #+#             */
/*   Updated: 2024/02/19 22:33:40 by oel-qasr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

char	*line_maker(char *b_line)
{
	char	*left_l;
	ssize_t	i;

	i = 0;
	while (b_line[i] != '\n' && b_line[i] != '\0')
		i++;
	if (b_line[i] == 0 || b_line[i + 1] == 0)
		return (NULL);
	i++;
	left_l = ft_substr(b_line, i, ft_strlen(b_line));
	if (!left_l)
		return (NULL);
	if (*left_l == 0)
	{
		free(left_l);
		left_l = NULL;
	}
	b_line[i] = 0;
	return (left_l);
}

char	*put_in_line(int fd, char **left_l, char *buffer)
{
	ssize_t	buffer_we_read;
	char	*temp;

	buffer_we_read = 1;
	while (buffer_we_read > 0)
	{
		buffer_we_read = read(fd, buffer, BUFFER_SIZE);
		if (buffer_we_read == -1)
			return (free(*left_l), *left_l = NULL);
		else if (buffer_we_read == 0)
			break ;
		buffer[buffer_we_read] = 0;
		temp = *left_l;
		*left_l = ft_strjoin(temp, buffer);
		if (*left_l == NULL)
			return (free(*left_l), *left_l = NULL);
		free(temp);
		temp = NULL;
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	return (*left_l);
}

char	*get_next_line(int fd)
{
	static char	*left;
	char		*line;
	char		*buffer;

	buffer = NULL;
	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE >= INT_MAX)
		return (NULL);
	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	line = put_in_line(fd, &left, buffer);
	free(buffer);
	if (!line)
		return (NULL);
	left = line_maker(line);
	return (line);
}
