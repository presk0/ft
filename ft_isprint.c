/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: supersko <ndionis@student.42mulhouse.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 16:48:16 by supersko          #+#    #+#             */
/*   Updated: 2022/02/24 13:34:27 by supersko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

struct s_point {
	int x;
	int y;
}

struct s_point pt1;

unsigned int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

#include "error_msg.h"
#include <ctype.h>
#include <string.h>

int test_strlen(char *str)
{
	if (strlen(str) != ft_strlen(str))
	{
		printf("differents output for str=%s\n\t
			strlen(str) = %d ; ft_strlen(str) = %d\n",
			str, strlen(str), ft_strlen(str));
		exit(0);
	}
}

int	main(int argc, char *argv[])
{
	test_strlen(str, "");
}
