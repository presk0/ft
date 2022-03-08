/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: supersko <ndionis@student.42mulhouse.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 19:17:07 by supersko          #+#    #+#             */
/*   Updated: 2022/03/08 14:18:03 by supersko         ###   ########.fr       */
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
	char	*num;

	len = ft_intlen(n);
	ret = (char *) malloc(sizeof(char) * (len + 1));
	if (!ret)
		return (NULL);
	if (n == -2147483648)
	{
		ft_strlcpy(ret, "-2147483648", 12);
		return (ret);
	}
	ret[len] = '\0';
	num = ret;
	if (n < 0)
	{
		*(num++) = '-';
		len--;
		n *= -1;

	}
	while (len--)
	{
		*(num + len) = (char)(n % 10) + '0';
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

	strnb = ft_itoa(-0);
	printf("%s\n", strnb);
	free(strnb);

	strnb = ft_itoa(1230);
	printf("%s\n", strnb);
	free(strnb);
}
*/
