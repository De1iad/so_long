/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obibby <obibby@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 17:48:59 by obibby            #+#    #+#             */
/*   Updated: 2022/04/10 17:50:08 by obibby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "./libft/libft.h"
# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include <stdint.h>

int		ft_printf(const char *str, ...);
int		print_int(char *str, char *flags, int width, int prec);
void	ft_flag_count(char *flags, int width, int prec);
int		ft_char_write(va_list vl, char *flags, int width);
int		ft_hexa_write(va_list vl, char *flags, int width, int prec);
int		ft_uint_write(va_list vl, char *flags, int width, int prec);
int		ft_int_write(va_list vl, char *flags, int width, int prec);
int		ft_ptr_write(va_list vl, char *flags, int width);
int		ft_str_write(va_list vl, char *flags, int width, int prec);
void	ft_bzero_printf(char *str, size_t n);

#endif