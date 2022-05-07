/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_arg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: supersko <ndionis@student.42mulhouse.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 19:13:11 by supersko          #+#    #+#             */
/*   Updated: 2022/05/07 18:34:46 by supersko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// return error if the arg is not an int
int	ft_atoi_arg(char *str_nb)
{
	int	nb;
	int	sign;
	int	loop_nb;

	sign = 1;
	nb = 0;
	loop_nb = 0;
	if (*str_nb == '-')
	{
		sign = -1;
		str_nb++;
	}
	while (*str_nb == '0')
		str_nb++;
	while (*str_nb && (*str_nb >= '0' && *str_nb <= '9') && loop_nb++ < 10)
		nb = (*str_nb++ - 48) + 10 * nb;
	if (nb != -2147483648)
		nb *= sign;
	if ((loop_nb > 9 && nb * sign < 0 && nb != -2147483648) || *str_nb != 0)
		error_msg(NULL);
	return (nb);
}
