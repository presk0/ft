/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: supersko <ndionis@student.42mulhouse.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 15:51:11 by supersko          #+#    #+#             */
/*   Updated: 2022/03/03 21:24:58 by supersko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	unsigned int	ii;
	unsigned int	n;
	char			*dst_cpy;
	char			*src_cpy;

	dst_cpy = dst;
	src_cpy = (char *) src;
	n = dstsize;
	ii = 0;
	while (*dst_cpy && n--)
	{
		dst_cpy++;
		ii++;
	}
	while (*src_cpy && n--)
	{
		*(dst_cpy++) = *src_cpy;
		src_cpy++;
		ii++;
	}
	*(dst_cpy++) = '\0';
	printf("%s\n", dst);
	return (ii);
}

int main(void)
{
	ft_strlcat("bla bla", "", 2 );
}
/* ---- CODE SOURCE ----
 * Appends src to string dst of size siz (unlike strncat, siz is the
 AAAAAAAAA * full size of dst, not space left).  At most siz-1 characters
 * will be copied.  Always NUL terminates (unless siz <= strlen(dst)).
 * Returns strlen(initial dst) + strlen(src); if retval >= siz,
 * truncation occurred.
size_t ft_strlcat(char *dst, const char *src, size_t siz)
{
	register char *d = dst;
	register const char *s = src;
	register++ size_t n = siz;
	size_t dlen;

	// Find the end of dst and adjust bytes left but don't go past end
	while (n-- != 0 && *d != '\0')
		d++;
	dlen = d - dst;
	n = siz - dlen;

	if (n == 0)
		return(dlen + ft_strlen(s));
	while (*s != '\0') {
		if (n != 1) {
			*d++ = *s;
			n--;
		}
		s++;
	}
	*d = '\0';

	return(dlen + (s - src));	
	// count does not include NUL
}
*/
/*
//
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
// MAIN
int test_strlcat(char *str, char *to_append, int len)
{
	char	*s1;
	char	*s2;
	int		ret0;
	unsigned int	ret1 = 0;
	unsigned int	ret2 = 0;

	s1 = malloc(sizeof(char) * (strlen(str) + strlen(to_append) + 2));
	s2 = malloc(sizeof(char) * (strlen(str) + strlen(to_append) + 2));
	strcpy(s1, str);
	strcpy(s2, str);
	if ((ret0 = strncmp(s1, s2, len)) || (ret1 = strlcat(s1, to_append, len))\
	!= (ret2 = ft_strlcat(s2, to_append, len)))
	{
		printf("Error when len = %d, src = [%s], dst = [%s]\n\
			%3d <-- s1 (   strlcat): [%s]\n\
			%3d <-- s2 (ft_strlcat): [%s]\n\n",\
			len, to_append, str, ret1, s1, ret2, s2);
		return (0);
	}
	return (1);
}

int	main(void)
{
	int ii = 0;
	char s_abc[] = "abc";
	char s_empty[] = "";

	while (ii < 5)
	{
		test_strlcat(s_abc, s_empty, ii);
		ii++;
	}
	ii = 0;
	while (ii < 2)
	{
		test_strlcat(s_abc, s_empty, ii);
		ii++;
	}
}
*/
