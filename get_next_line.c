/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pibouill <pibouill@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 13:51:39 by pibouill          #+#    #+#             */
/*   Updated: 2024/10/27 14:43:36 by pibouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>

char	*clean_stash(char *stash)
{
	char	*cleaned_stash;
	int		i;
	int		j;

	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (stash[i] && stash[i] == '\n')
		i++;
	if (stash[i] == 0)
	{
		free(stash);
		return (NULL);
	}
	cleaned_stash = malloc(sizeof(char) * (ft_strlen(stash) - i) + 1);
	if (cleaned_stash == NULL)
		return (NULL);
	j = 0;
	while (stash[i])
		cleaned_stash[j++] = stash[i++];
	cleaned_stash[j] = '\0';
	free(stash);
	return (cleaned_stash);
}

char	*read_to_stash(char *stash, int fd)
{
	ssize_t	readed;
	char	*buffer;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buffer == NULL)
		return (NULL);
	readed = 1;
	while (readed != 0 && !ft_strchr(stash, '\n'))
	{
		readed = read(fd, buffer, BUFFER_SIZE);
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

char	*stash_to_line(char *stash)
{
	int		i;
	char	*line;

	i = 0;
	if (stash[i] == 0)
		return (NULL);
	while (stash[i] && stash[i] != '\n')
		i++;
	line = malloc(sizeof(char) * i + 2);
	if (line == NULL)
		return (NULL);
	i = 0;
	while (stash[i] && stash[i] != '\n')
	{
		line[i] = stash[i];
		i++;
	}
	if (stash[i] == '\n')
	{
		line[i] = stash[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*stash;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stash = read_to_stash(stash, fd);
	if (stash == NULL)
		return (NULL);
	line = stash_to_line(stash);
	stash = clean_stash(stash);
	return (line);
}

/*int	main(int argc, char **argv)*/
/*{*/
	/*int     fd;*/
	/*char    *line;*/
	/*(void)argc;*/
	/*fd = open(argv[1], O_RDONLY);*/
	/*while (1)*/
	/*{*/
		/*line = get_next_line(fd);*/
		/*if (line == NULL)*/
			/*break ;*/
		/*printf("%s", line);*/
		/*free(line);*/
	/*}*/
	/*fd = close(fd);*/
	/*return (0);*/
/*}*/
