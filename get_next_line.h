/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pibouill <pibouill@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 12:51:50 by pibouill          #+#    #+#             */
/*   Updated: 2023/11/27 12:43:22 by pibouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <unistd.h>

char	*get_next_line(int fd);
char	*read_to_stash(char *stash, int fd);
char	*stash_to_line(char *stash);
char	*clean_stash(char *stash);
int		ft_strlen(char *str);
char	*ft_strchr(const char *str, int c);
char	*ft_strjoin(char *str1, char *str2);

#endif
