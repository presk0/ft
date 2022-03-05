/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: supersko <ndionis@student.42mulhouse.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 19:17:07 by supersko          #+#    #+#             */
/*   Updated: 2022/03/05 12:33:08 by supersko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_intlen(int n)
{
	int	len;

	len = 0;
	if (n < 0)
	{
		n *= -1;
		len++;
	}
	while (n > 9)
	{
		n /= 10;
		len++;
	}
	return (++len);
}

char	*ft_itoa(int n)
{
	int		len;
	char	*ret;

	if (n == -2147483648)
		return ("-2147483648");
	len = ft_intlen(n);
	ret = (char *) malloc(sizeof(char) * (len + 1));
	ret[len] = '\0';
	if (n < 0)
	{
		*(ret) = '-';
		n *= -1;
	}
	while (n > 0)
	{
		*(ret + --len) = (char)(n % 10) + '0';
		n /= 10;
	}
	return (ret);
}
/*
//
#include <stdio.h>
// MAIN
int main(void)
{
	char	*strnb;

	strnb = ft_itoa(-123);
	printf("%s\n", strnb);
	free(strnb);
}
*/
