/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: supersko <ndionis@student.42mulhouse.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 17:24:17 by supersko          #+#    #+#             */
/*   Updated: 2022/04/25 00:59:33 by supersko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINT_H
# define FT_PRINT_H
# include "libft.h"
# include <stdarg.h>

size_t	ft_print_arg(va_list *ap, char *after_percent);
size_t	ft_print_str(char *str);
size_t	ft_print_char(char c);
size_t	ft_print_hexa(long long unsigned int num, char CASE);
void	ft_recursive_print_addr(long long unsigned int num, size_t *len);
size_t	ft_print_addr(void *num);
size_t	ft_recursive_print_int(int num, size_t *len);
size_t	ft_print_int(int num);
size_t	ft_recursive_print_unsigned(unsigned int num, size_t *len);
size_t	ft_print_unsigned(unsigned int num);
int     ft_is_flag(char c);
size_t  printing_loop(char *str, va_list *ap);
int     ft_printf(const char *str0, ...);
#endif
