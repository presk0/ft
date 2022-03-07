/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: supersko <ndionis@student.42mulhouse.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 16:48:16 by supersko          #+#    #+#             */
/*   Updated: 2022/03/07 17:39:04 by supersko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(char c)
{
	if (c == '\t' || c == '\n' || c == '\v' || \
		c == '\f' || c == '\r' || c == ' ')
		return (1);
	else
		return (0);
}

static int	c_to_i(char c)
{
	return ((int) c - (int) '0');
}

int	ft_atoi(char *str)
{
	long int		sign;
	long int		nbr;

	sign = 1;
	while (ft_isspace(*str))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str++ == '-')
			sign *= -1;
	}
	nbr = 0;
	while (ft_isdigit(*str))
	{
		nbr *= 10;
		nbr += (long int) c_to_i(*str++);
	}
	return ((int)(sign * nbr));
}

/*
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// MAIN
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
*/
