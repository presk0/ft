/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nidionis <nidionis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 19:17:07 by supersko          #+#    #+#             */
/*   Updated: 2024/10/27 14:57:10 by nidionis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_intlen(int n)
{
	int	len;

	len = 0;
	if (n == -2147483648)
		return (11);
	else if (n <= 0)
	{
		n *= -1;
		len++;
	}
	while (n > 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

static void	make_str(int *n, char *str, int len)
{
	if (*n < 0)
	{
		*str++ = '-';
		len--;
		*n *= -1;
	}
	while (len--)
	{
		*(str + len) = (char)(*n % 10) + '0';
		*n /= 10;
	}
}

char	*ft_itoa(int n)
{
	int		len;
	char	*str;

	len = ft_intlen(n);
	str = (char *) ft_calloc(len + 1, sizeof(char));
	if (!str)
		return (NULL);
	if (n == -2147483648)
	{
		ft_strlcpy(str, "-2147483648", 12);
		return (str);
	}
	make_str(&n, str, len);
	return (str);
}

/*
//
#include <stdio.h>
// MAIN
int main(int argc, char **argv)
{
	char	*strnb = argv[1];

	strnb = ft_itoa(atoi(strnb));
	printf("%s\n", strnb);
	free(strnb);
}
*/
