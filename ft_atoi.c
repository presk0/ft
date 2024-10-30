/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: supersko <ndionis@student.42mulhouse.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 16:48:16 by supersko          #+#    #+#             */
/*   Updated: 2024/10/30 20:06:23 by nidionis         ###   ########.fr       */
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
	nbr = 0;
	if (str0)
	{
		while (*str == ' ' || (*str >= 9 && *str <= 13))
			str++;
		if (*str == '-' || *str == '+')
			if (*str++ == '-')
				sign *= -1;
		while (ft_isdigit(*str))
			nbr = *str++ - '0' + nbr * 10;
	}
	return (sign * nbr);
}

/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv)
{
	printf("atoi = %d\n", atoi(0));
	printf("ft_atoi = %d\n", ft_atoi(0));
	//printf("ft_atoi = %d\n", ft_atoi(NULL));
	//printf("atoi = %d\n", atoi(NULL));
	//printf("atoi = %d\n", atoi(argv[1]));
	//printf("ft_atoi = %d\n", ft_atoi(argv[1]));
}
*/
