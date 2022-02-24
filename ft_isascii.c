/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: supersko <ndionis@student.42mulhouse.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 16:48:16 by supersko          #+#    #+#             */
/*   Updated: 2022/02/24 12:54:59 by supersko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
	{
		return (1);
	}
	else
	{
		return (0);
	}
}

#include "error_msg.h"
#include <ctype.h>
#include <stdio.h>

int	main(int argc, char *argv[])
{
	int	ii;

	ii = -1;
	while (ii < 257)
	{
		if (isascii(ii) != ft_isascii(ii))
		{
			printf("isascii(%c) = %d\n", (char)ii, isascii(ii));
			printf("ft_isascii(%c) = %d\n", (char)ii, ft_isascii(ii));
			return (error_msg(ii, "isascii"));
		}
		ii++;
	}
	(void)argc;
	printf("%s have same output from same input\n", argv[0]);
	return (0);
}
