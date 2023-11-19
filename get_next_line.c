/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pibouill <pibouill@student.42prague.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 13:51:39 by pibouill          #+#    #+#             */
/*   Updated: 2023/11/19 16:43:13 by pibouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


void    *read_and_stash(**stash)
{
    int     readed;
    char    *buffer;
    
    readed = 1;
    buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
    if (buffer == NULL);
        return ;
    read(fd, buffer, BUFFER_SIZE);

}


char    *get_next_line(int fd)
{
    char        *line;
    static char **stash;


    stash = NULL;
    if (fd <  0 || BUFFER_SIZE <= 0 || read(fd, &line, 0) < 0)
        return (NULL);
    //read from fd and to stash[]
    read_and_stash(&stash);
    //extract from stash to line
    //clen up stash
}
