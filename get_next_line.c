/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbarreir <nbarreir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 21:29:53 by nbarreir          #+#    #+#             */
/*   Updated: 2021/03/06 22:22:28 by nbarreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*do_line(char *str_temp, int n, char **line)
{
	char	*str_extra;
	int		i;

	i = 0;
	while (*(str_temp + i) != '\n' || *(str_temp + i) != '\0')
		i++;
	*(str_temp + i) = '\0';
	if(!(*line = ft_strdup(str_temp)))
		return (NULL);
	if (n != 0)
		if(!(str_extra = ft_strdup(str_temp + i + 1)))
			return (NULL);
	free(str_temp);
	return(str_extra);
}

int		do_read(int fd, char *buffer, char **str_temp, int n)
{
	while(!(n = read(fd, buffer, BUFFER_SIZE)) && (!(ft_strchr(*str_temp, '\n'))))
	{
		n = read(fd, buffer, BUFFER_SIZE);
		if((!n))
		{
			free(buffer);
			return(0);
		}
		*(buffer + n) = '\0';
		*str_temp = ft_strjoin(*str_temp, buffer);
	}
	free(buffer);
	return(1);
}

int		get_next_line(int fd, char **line)
{
	static char	*str_temp;
	char		*buffer;
	int			n;

	n = 1;
	if (!line || fd < 0  || fd > LIMITED || BUFFER_SIZE <= 0)
		return (-1);
	if (!str_temp)
		str_temp = ft_strdup("");
	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (-1);
	if(!(do_read(fd, buffer, &str_temp, n)))
		return (-1);
	str_temp = do_line(str_temp, n, line);
	if(!n)
		return (0);
	return (1);
}
