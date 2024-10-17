/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_err.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nidionis <nidionis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 19:13:11 by supersko          #+#    #+#             */
/*   Updated: 2024/10/17 15:42:06 by nidionis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// return error if the arg is not an int
static int	ft_isspace(const char c)
{
	if (c == '\t' || c == '\n' || c == '\v' || \
		c == '\f' || c == '\r' || c == ' ')
		return (1);
	else
		return (0);
}

static long int	c_to_i(char c)
{
	return ((long int) c - (long int) '0');
}

int	ft_atoi_err(char *str)
{
	int			sign;
	long int	nbr;

	if (!str)
		return (0);
	sign = 1;
	while (ft_isspace(*str))
		str++;
	if (*str == '-' || *str == '+')
		if (*str++ == '-')
			sign *= -1;
	nbr = 0;
	while (ft_isdigit(*str))
	{
		nbr *= 10;
		nbr += (long int) c_to_i(*str++);
		if (nbr > 2147483647)
			error_msg("[ft_atoi_err] not int value");
	}
	return (sign * nbr);
}
/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void	ft_atoi_tester(int argc, char **argv)
{
	if (argc != 2)
	{
		printf("usage : ./ft_atoi_err [str]\n");
		exit(0);
	}
	if (ft_atoi_err(argv[1]) != atoi(argv[1]))
	{
		printf("%i\n", ft_atoi(argv[1]));
		printf("differents output for str=%s\n", argv[1]);
		exit(1);
	}
}
int	main(int argc, char **argv)
{
	ft_atoi_tester(argc, argv);
	return (0);
}
*/