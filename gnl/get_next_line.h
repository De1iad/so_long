/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obibby <obibby@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 11:27:38 by obibby            #+#    #+#             */
/*   Updated: 2022/05/02 13:31:37 by obibby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

typedef enum e_buff {
	BUFFER_SIZE = 50
}	t_buff;

char	*get_next_line(int fd);
char	*rec_find(char *data, int fd, char *jstr);
char	*str_make(char *data, int i, int fd, int nl);
void	*ft_memmove_gnl(char *dest, char *src, size_t n);
char	*ft_strjoin_gnl(char *s1, char *s2);
size_t	ft_strlen_gnl(const char *str);
size_t	ft_strlcpy_gnl(char *dest, const char *src, size_t size);
size_t	ft_strlcat_gnl(char *dest, const char *src, size_t size);
void	*alloc_bzero(char *data);

#endif