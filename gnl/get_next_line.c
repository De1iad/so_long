/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obibby <obibby@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 17:02:51 by obibby            #+#    #+#             */
/*   Updated: 2022/05/02 13:31:48 by obibby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_memmove_gnl(char *dest, char *src, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		dest[i] = src[i];
		i++;
	}
	while (dest[n])
		dest[n++] = '\0';
	return (0);
}

void	ft_bzero_gnl(void *str, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
		((char *)str)[i++] = '\0';
}

char	*str_make(char *data, int i, int fd, int nl)
{
	char	*str;
	int		x;

	x = i;
	str = malloc((i + 2) * sizeof(char));
	if (!str)
		return (0);
	while (x >= 0)
	{
		str[x] = data[x];
		x--;
	}
	str[i + 1] = '\0';
	if (i < BUFFER_SIZE && nl == 1)
		ft_memmove_gnl(data, data + i + 1, BUFFER_SIZE - i);
	else
	{
		ft_bzero_gnl(data, BUFFER_SIZE + 1);
		read(fd, data, BUFFER_SIZE);
	}
	return (str);
}

char	*find_n(char *data, int fd, char *jstr)
{
	int		i;
	char	*str;

	while (data[0] != '\0')
	{
		i = 0;
		while (data[i] && data[i] != '\n')
			i++;
		if (data[i] == '\n')
		{
			if (!jstr)
				return (str_make(data, i, fd, 1));
			else
				return (ft_strjoin_gnl(jstr, str_make(data, i, fd, 1)));
		}
		if (!jstr)
			jstr = str_make(data, i, fd, 0);
		else
		{
			str = str_make(data, i, fd, 0);
			jstr = ft_strjoin_gnl(jstr, str);
		}
	}
	return (jstr);
}

char	*get_next_line(int fd)
{
	static char	*data[__FD_SETSIZE];
	char		*str;

	str = 0;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!data[fd])
		data[fd] = alloc_bzero(data[fd]);
	if (!data[fd])
		return (NULL);
	if (!data[fd][0])
	{
		if (read(fd, data[fd], BUFFER_SIZE) < 1)
		{
			if (data[fd])
				free(data[fd]);
			data[fd] = NULL;
			return (NULL);
		}
	}
	str = find_n(data[fd], fd, str);
	return (str);
}
