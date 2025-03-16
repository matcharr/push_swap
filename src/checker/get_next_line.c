/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathis <mathis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023-11-15 10:00:00 by mathis            #+#    #+#             */
/*   Updated: 2023-11-15 10:00:00 by mathis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

/* Allocate and initialize a new line */
char	*init_line(void)
{
	char	*line;

	line = malloc(1);
	if (!line)
		return (NULL);
	line[0] = '\0';
	return (line);
}

/* Process read buffer and append to line */
char	*process_buffer(char *line, char *buffer, int bytes_read)
{
	char	*temp;

	buffer[bytes_read] = '\0';
	temp = line;
	line = malloc(ft_strlen(line) + 2);
	if (!line)
	{
		free(temp);
		return (NULL);
	}
	ft_strcpy(line, temp);
	ft_strcat(line, buffer);
	free(temp);
	return (line);
}

/* Read a line from standard input */
char	*get_next_line(int fd)
{
	char	buffer[2];
	char	*line;
	int		bytes_read;

	line = init_line();
	if (!line)
		return (NULL);
	bytes_read = read(fd, buffer, 1);
	while (bytes_read > 0)
	{
		line = process_buffer(line, buffer, bytes_read);
		if (!line)
			return (NULL);
		if (buffer[0] == '\n')
			break ;
		bytes_read = read(fd, buffer, 1);
	}
	if (bytes_read <= 0 && line[0] == '\0')
	{
		free(line);
		return (NULL);
	}
	return (line);
}
