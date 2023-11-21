/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pibouill <pibouill@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 13:51:39 by pibouill          #+#    #+#             */
/*   Updated: 2023/11/21 15:37:15 by pibouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>

char	*read_to_stash(char *stash, int fd)
{
	int		readed;
	char	*buffer;

	readed = 1;
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buffer == NULL)
		return (NULL);
	while (readed != 0 && !ft_strchr(buffer, '\n'))
	{
		readed = (int)read(fd, buffer, BUFFER_SIZE);
		if (readed < 0)
		{
			free(buffer);
			return (NULL);
		}
		buffer[readed] = '\0';
		stash = ft_strjoin(stash, buffer);
	}
	free(buffer);
	return (stash);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*stash;

	stash = NULL;
	if (fd <  0 || BUFFER_SIZE <= 0 || read(fd, &line, 0) < 0)
		return (NULL);
	stash = read_to_stash(stash, fd);
	if (stash == NULL)
		return (NULL);
	line = stash_to_line(stash);
	//extract from stash to line
	//clen up stash
	clean_stash();
	return (line);
}
