/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: supersko <ndionis@student.42mulhouse.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 15:54:04 by supersko          #+#    #+#             */
/*   Updated: 2022/04/25 01:02:59 by supersko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_print_arg(va_list *ap, char *after_percent)
{
	if (*after_percent == 'c')
    {
		(ft_putchar_fd((char) va_arg(*ap, int), 1));
        return (1);
    }
	else if (*after_percent == 's')
		return (ft_print_str(va_arg(*ap, char *)));
	else if (*after_percent == 'd' || *after_percent == 'i')
		return (ft_print_int(va_arg(*ap, int)));
	else if (*after_percent == 'u')
		return (ft_print_unsigned(va_arg(*ap, unsigned int)));
	else if (*after_percent == 'p')
		return (ft_print_addr(va_arg(*ap, void *)));
	else if (*after_percent == 'x')
		return (ft_print_hexa(va_arg(*ap, unsigned int), 'm'));
	else if (*after_percent == 'X')
		return (ft_print_hexa(va_arg(*ap, unsigned int), 'M'));
	else if (*after_percent == '%')
		return (write(1, "%", 1));
	else
		return (0);
}

static int	ft_is_flag(char c)
{
	char	flags[20];
	int		ii;

	ii = 0;
	ft_strlcpy(flags, "csidupxX%", 20);
	while (flags[ii])
		if (c == flags[ii++])
			return (1);
	return (0);
}

size_t	printing_loop(char *str, va_list *ap)
{
	size_t	len_str;
	size_t	len_str_written;
	int		is_flag;

	len_str_written = 0;
	while (*str)
	{
		is_flag = ft_is_flag(*(str + 1));
		if (*str == '%' && is_flag)
		{
			str++;
			len_str_written += ft_print_arg(ap, str);
			str++;
		}
		else if (*str == '%' && !is_flag)
			str++;
		else
		{
			len_str = ft_strlen_char(str, '%');
			len_str_written += write(1, str, len_str);
			str += len_str;
		}
	}
	return (len_str_written);
}

int	ft_printf(const char *str0, ...)
{
	va_list			ap;
	char			*str;
	size_t			len_str_written;

	str = (char *) str0;
	va_start(ap, str0);
	len_str_written = printing_loop(str, &ap);
	va_end(ap);
	return (len_str_written);
}

/*
// MAIN
int main(void)
{
	int strlen;

	strlen = ft_printf("a%ia\n", 42);
	printf("strlen: %d\n", strlen);
	ft_printf("\n");

	printf("%d\n", printf("%d, %p0000\n", 10, &strlen));
	printf("%d\n", ft_printf("%d, %p0000\n", 10, &strlen));
	printf("retour de printf: %d\n", printf(" %i %i %i %i %i %i %i\n",  NULL,
	LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42));
	printf("retour de printf: %d\n", ft_printf(" %i %i %i %i %i %i %i\n", NULL,
	LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42));
	printf("retour de printf: %d\n", ft_printf("%x\n", -42));
	printf("retour de printf: %d\n", printf("%x\n", -42));
	printf("(printf    : %d)", printf("%c", '0'));
	printf("\n");
	printf("(ft_printf : %d)", ft_printf("%c", '0'));
	printf("\n");
	printf("\n");
	printf("(printf    : %d)", ft_printf(" %c ", '0'));
	printf("\n");
	printf("(ft_printf : %d)", printf(" %c ", '0'));
	printf("\n");
	printf("\n");
	printf("(printf    : %d)", ft_printf(" %c", '0' - 256)); 
	printf("\n");
	printf("(ft_printf : %d)", printf(" %c", '0' - 256)); 
	printf("\n");
	printf("\n");
	printf("(printf    : %d)", ft_printf("%c ", '0' + 256));
	printf("\n");
	printf("(ft_printf : %d)", printf("%c ", '0' + 256));
	printf("\n");
	printf("\n");
	printf("(printf    : %d)", ft_printf(" %c %c %c ", '0', 0, '1'));
	printf("\n");
	printf("(ft_printf : %d)", printf(" %c %c %c ", '0', 0, '1'));
	printf("\n");
	printf("\n");
	printf("(printf    : %d)", ft_printf(" %c %c %c ", ' ', ' ', ' '));
	printf("\n");
	printf("(ft_printf : %d)", printf(" %c %c %c ", ' ', ' ', ' '));
    */
