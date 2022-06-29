/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obibby <obibby@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 10:36:07 by obibby            #+#    #+#             */
/*   Updated: 2022/04/24 01:05:13 by obibby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlcat_gnl(char *dest, const char *src, size_t size)
{
	size_t	i;
	int		destlen;
	int		srclen;

	i = 0;
	destlen = ft_strlen_gnl(dest);
	srclen = ft_strlen_gnl(src);
	while (dest[i] != '\0')
	{
		if (i == size)
			return (size + srclen);
		i++;
	}
	while (src[i - destlen] != '\0' && i < size - 1 && size > 0)
	{
		dest[i] = src[i - destlen];
		i++;
	}
	dest[i] = '\0';
	return (destlen + srclen);
}

size_t	ft_strlcpy_gnl(char *dest, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size == 0)
		return (ft_strlen_gnl(src));
	while (src[i] != '\0' && i < size - 1)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (ft_strlen_gnl(src));
}

size_t	ft_strlen_gnl(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin_gnl(char *s1, char *s2)
{
	size_t	len;
	char	*ptr;

	if (s1 == NULL || s2 == NULL)
	{
		free(s2);
		return (s1);
	}
	len = (ft_strlen_gnl(s1) + ft_strlen_gnl(s2) + 1);
	ptr = malloc(sizeof(char) * len);
	if (!ptr)
		return (NULL);
	ft_strlcpy_gnl(ptr, s1, (ft_strlen_gnl(s1) + 1));
	ft_strlcat_gnl(ptr, s2, len);
	free(s1);
	free(s2);
	return (ptr);
}

void	*alloc_bzero(char *data)
{
	int	i;

	i = 0;
	data = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!data)
		return (NULL);
	while (i < BUFFER_SIZE + 1)
		data[i++] = '\0';
	return (data);
}
