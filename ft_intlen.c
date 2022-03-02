/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: supersko <ndionis@student.42mulhouse.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 19:25:15 by supersko          #+#    #+#             */
/*   Updated: 2022/03/02 11:19:30 by supersko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	ft_intlen(int n)
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
/*
//
#include <stdio.h>
// MAIN
int main(void)
{
	printf("%d\n", ft_intlen(0));
	printf("%d\n", ft_intlen(-0));
	printf("%d\n", ft_intlen(-1));
	printf("%d\n", ft_intlen(1));
	printf("%d\n", ft_intlen(-10));
	printf("%d\n", ft_intlen(1234567890));
}
*/
