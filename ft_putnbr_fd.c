/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: supersko <ndionis@student.42mulhouse.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 11:12:03 by supersko          #+#    #+#             */
/*   Updated: 2022/03/03 11:37:48 by supersko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void ft_putnbr_fd(int n, int fd)
{
	n += (int) '0';
	write(fd, (char *) &n, 1);
}
/*
//
#include <stdio.h>
// MAIN
int main(void)
{
	ft_putnbr_fd(3, 1);
	write(1, "\n", 1);
}
*/
