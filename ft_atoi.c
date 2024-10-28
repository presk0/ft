/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: supersko <ndionis@student.42mulhouse.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 16:48:16 by supersko          #+#    #+#             */
/*   Updated: 2024/10/28 18:25:55 by nidionis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str0)
{
	int			sign;
	long int	nbr;
	char		*str;

	sign = 1;
	str = (char *)str0;
	while (ft_strchr("\t\n\v\f\r ", *str))
		str++;
	if (*str == '-' || *str == '+')
		if (*str++ == '-')
			sign *= -1;
	nbr = 0;
	while (ft_isdigit(*str))
		nbr = *str++ - '0' + nbr * 10;
	return (sign * nbr);
}

/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv)
{
	printf("ft_atoi = %d\n", ft_atoi(""));
	printf("atoi = %d\n", atoi(""));
	//printf("ft_atoi = %d\n", ft_atoi(NULL));
	//printf("atoi = %d\n", atoi(NULL));
	//printf("atoi = %d\n", atoi(argv[1]));
	//printf("ft_atoi = %d\n", ft_atoi(argv[1]));
}

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
