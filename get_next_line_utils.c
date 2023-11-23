/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pibouill <pibouill@student.42prague.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 13:58:38 by pibouill          #+#    #+#             */
/*   Updated: 2023/11/23 18:49:53 by pibouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>
#include <stdio.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strchr(const char *str, int c)
{
	char	*s;

	if (str == NULL)
		return (NULL);
	s = (char *)str;
	while (*s)
	{
		if (*s == (char) c)
			return (s);
		s++;
	}
	if ((char) c == '\0')
		return (s);
	return (NULL);
}

char	*ft_strjoin(char *str1, char *str2)
{
	char		*new;
	int			i;
	int			j;

	if (str1 == NULL)
	{
		str1 = malloc(sizeof(char));
		str1[0] = '\0';
	}
	if (str1 == NULL || str2 == NULL)
		return (NULL);
	i = 0;
	j = 0;
	new = malloc(sizeof(char) * ((ft_strlen(str1) + ft_strlen(str2)) + 1));
	if (new == NULL)
		return (NULL);
	while (str1[i])
		new[j++] = str1[i++];
	i = 0;
	while (str2[i])
		new[j++] = str2[i++];
	new[j] = '\0';
	free(str1);
	return (new);
}
