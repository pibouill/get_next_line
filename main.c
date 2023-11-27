/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pibouill <pibouill@student.42prague.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 13:18:58 by pibouill          #+#    #+#             */
/*   Updated: 2023/11/27 12:43:55 by pibouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>


int main(int argc, char **argv)
{
    int     fd;
    char    *line;
	(void)argc;
    fd = open(argv[1], O_RDONLY);
    while (1)
    {
        line = get_next_line(fd);
        if (line == NULL)
            break ;
        printf("%s", line);
        free(line);
    }
	fd = close(fd);
    return (0);
}
