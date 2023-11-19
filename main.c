/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pibouill <pibouill@student.42prague.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 13:18:58 by pibouill          #+#    #+#             */
/*   Updated: 2023/11/19 13:21:34 by pibouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <sys/stat.h>
#include <fnctl.h>

int main()
{
    int fd;

    fd = open("test.txt", O_RDONLY);
    get_next_line(fd);
    return (0);
}
