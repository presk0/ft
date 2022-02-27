/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: supersko <ndionis@student.42mulhouse.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 16:48:16 by supersko          #+#    #+#             */
/*   Updated: 2022/02/27 14:41:22 by supersko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	my_isspace(char c)
{
	if (c == '\t' || c == '\n' || c == '\v' ||
		c == '\f' || c == '\r' || c == ' ')
		return (1);
	else
		return (0);
}

int my_isdigit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

int	c_to_i(char c)
{
	if (my_isdigit(c))
		return ((int) c - (int) '0');
	else
		return (-1);
}

int	ft_atoi(char *str)
{
	unsigned int	ii;
	long int		sign;
	long int		nbr;

	ii = 0;
	sign = 1;
	while (my_isspace(str[ii]))
		ii++;
	if (str[ii] == '-' || str [ii] == '+')
	{
		if (str[ii] == '-')
			sign *= -1;
		ii++;
	}
	nbr = 0;
	while (my_isdigit(str[ii]))
	{
		nbr *= 10;
		nbr += c_to_i(str[ii]);
		ii++;
	}
	return ((int) (sign * nbr));
}

#include "error_msg.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int	main(void)
{
	char *nb;

	nb = malloc(50);
	strcpy(nb, "2147483647");
	if (atoi(nb) != ft_atoi(nb))
	{
		printf("atoi(%s) = %d\n", nb, atoi(nb));
		printf("ft_atoi(%s) = %d\n", nb, ft_atoi(nb));
		free(nb);
	}
	strcpy(nb, " 	-2147483648");
	if (atoi(nb) != ft_atoi(nb))
	{
		printf("atoi(%s) = %d\n", nb, atoi(nb));
		printf("ft_atoi(%s) = %d\n", nb, ft_atoi(nb));
		free(nb);
	}
	strcpy(nb, " 	-0aa");
	if (atoi(nb) != ft_atoi(nb))
	{
		printf("atoi(%s) = %d\n", nb, atoi(nb));
		printf("ft_atoi(%s) = %d\n", nb, ft_atoi(nb));
		free(nb);
	}
	strcpy(nb, "");
	if (atoi(nb) != ft_atoi(nb))
	{
		printf("atoi(%s) = %d\n", nb, atoi(nb));
		printf("ft_atoi(%s) = %d\n", nb, ft_atoi(nb));
		free(nb);
	}
	strcpy(nb, "   -0002365s654");
	if (atoi(nb) != ft_atoi(nb))
	{
		printf("atoi(%s) = %d\n", nb, atoi(nb));
		printf("ft_atoi(%s) = %d\n", nb, ft_atoi(nb));
		free(nb);
	}
	printf("All tested\n");
	printf("All tested\n");
	free(nb);
	return (0);
}
