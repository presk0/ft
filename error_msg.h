/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_msg.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: supersko <ndionis@student.42mulhouse.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 16:18:48 by supersko          #+#    #+#             */
/*   Updated: 2022/02/23 16:53:31 by supersko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	error_msg(int error_code, char *error_loc)
{
	printf("[debug] ERROR AT:\t%s\tnum:\t%d\n", error_loc, error_code);
	return (error_code);
}
