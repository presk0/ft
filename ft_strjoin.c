/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nidionis <nidionis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 15:51:11 by supersko          #+#    #+#             */
/*   Updated: 2024/11/10 16:17:17 by nidionis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t			len_s1;
	size_t			len_s2;
	char			*ret;

	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	ret = malloc(len_s2 + len_s1 + 1 * sizeof(char));
	*ret = '\0';
	if (!ret)
		return (NULL);
	if (s1)
		ft_strlcpy(ret, s1, len_s1 + 1);
	if (s2)
		ft_strlcat(ret, s2, len_s1 + len_s2 + 1);
	return (ret);
}
