/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nidionis <nidionis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 15:51:11 by supersko          #+#    #+#             */
/*   Updated: 2024/10/23 18:17:31 by nidionis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		*((char *) s + i) = '\0';
		i++;
	}
	return (s);
}

/*
#include <stdio.h>

void	print_mem(void *s)
{
	int	ii;
	ii = 0;
	while (ii < 10)
	{
		printf("%c", *((char *) s + ii));
		ii++;
	}
	printf("\n");
}
void	test_bzero(void *s, size_t n)
{
	print_mem(s);
	print_mem(ft_bzero(s, n)); //ft_bzero(s, n);
}
int main(int argc, char **argv)
{
	void *s;

	s = (void *) argv[1];
	test_bzero(s, atoi(argv[2]) );
	return (0);
}
*/
