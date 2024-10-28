/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: supersko <ndionis@student.42mulhouse.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 16:48:16 by supersko          #+#    #+#             */
/*   Updated: 2024/10/28 18:36:15 by nidionis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int c)
{
	return (c >= 32 && c < 127);
}

/*
//
#include "error_msg.h"
#include <ctype.h>
#include <stdio.h>
// MAIN
int	main(int argc, char *argv[])
{
	int	ii;

	ii = -1;
	while (ii < 257)
	{
		if (isprint(ii) != ft_isprint(ii))
		{
			printf("isprint(%c) = %d\n", (char)ii, isprint(ii));
			printf("ft_isprint(%c) = %d\n", (char)ii, ft_isprint(ii));
			return (error_msg(ii, "isprint"));
		}
		ii++;
	}
	(void)argc;
	printf("%s have same output from same input\n", argv[0]);
	return (0);
}
*/
