/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbarreir <nbarreir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 23:19:36 by nbarreir          #+#    #+#             */
/*   Updated: 2021/03/08 23:19:58 by nbarreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t		ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (i);
	while (s[i] != '\0')
		i++;
	return (i);
}

char		*ft_strjoin(char *s1, char *s2)
{
	char	*temp;

	if (!s1 && !s2)
		return (NULL);
	if (!(temp = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char))))
		return (NULL);
	str_copy(temp, s1, (ft_strlen(s1) + 1));
	str_copy((temp + ft_strlen(s1)), s2, (ft_strlen(s2) + 1));
	free(s1);
	return (temp);
}

size_t		str_copy(char *dst, char *src, size_t size)
{
	size_t i;

	i = 0;
	if (!(src))
		return (0);
	if (size == 0)
		return (ft_strlen(src));
	while (*(src + i) != '\0' && i < size - 1)
	{
		*(dst + i) = *(src + i);
		i++;
	}
	*(dst + i) = '\0';
	return (ft_strlen(src));
}

char		*ft_strchr(const char *s, int c)
{
	char	*str;
	int		i;

	str = (char *)s;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == (char)c)
			return (&str[i]);
		i++;
	}
	if ((char)c == '\0')
		return (&str[i]);
	return (0);
}

char		*ft_strdup(char *s)
{
	char	*temp;

	if (!(temp = malloc((ft_strlen(s) + 1) * sizeof(char))))
		return (NULL);
	str_copy(temp, s, ft_strlen(s) + 1);
	return (temp);
}
