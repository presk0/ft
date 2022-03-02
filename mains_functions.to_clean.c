#include "header.h"

int	ft_atoi_cmpTest(void)
{
	char *nb;

	nb = malloc(50);
	strcpy(nb, "2147483647");
	if (atoi(nb) != ft_atoi(nb))
	{
		printf("atoi(%s) = %d\n", nb, atoi(nb));
		printf("ft_atoi(%s) = %d\n", nb, ft_atoi(nb));
		free(nb);
	}
	strcpy(nb, " 	-2147483648");
	if (atoi(nb) != ft_atoi(nb))
	{
		printf("atoi(%s) = %d\n", nb, atoi(nb));
		printf("ft_atoi(%s) = %d\n", nb, ft_atoi(nb));
		free(nb);
	}
	strcpy(nb, " 	-0aa");
	if (atoi(nb) != ft_atoi(nb))
	{
		printf("atoi(%s) = %d\n", nb, atoi(nb));
		printf("ft_atoi(%s) = %d\n", nb, ft_atoi(nb));
		free(nb);
	}
	strcpy(nb, "");
	if (atoi(nb) != ft_atoi(nb))
	{
		printf("atoi(%s) = %d\n", nb, atoi(nb));
		printf("ft_atoi(%s) = %d\n", nb, ft_atoi(nb));
		free(nb);
	}
	strcpy(nb, "   -0002365s654");
	if (atoi(nb) != ft_atoi(nb))
	{
		printf("atoi(%s) = %d\n", nb, atoi(nb));
		printf("ft_atoi(%s) = %d\n", nb, ft_atoi(nb));
		free(nb);
	}
	printf("All tested\n");
	printf("All tested\n");
	free(nb);
	return (0);
}


int test_bzero(char *str, int c, int len, int buf_size)
{
	char	s1[1000];
	char	s2[1000];
	int		ii = 0;

	strcpy(s1, str);
	strcpy(s2, str);
	bzero(s1, len);
	ft_bzero(s2, len);
	while (ii < len)
	{
		if (s1[ii] != s2[ii])
		{
			printf("differents output for str=[%s]\nbzero(str) = [%s]\nft_bzero(str) = [%s]\nlen/str_bufsize = %d\nbuf_size = %d\n", str, s1, s2, len, buf_size);
			printf("\n");
			printf("\n");
			return (1);
		}
		ii++;
	}
	return (0);
}

int	ft_bzero_cmpTest(int argc, char *argv[])
{
	int ii = 0;
	int jj = 0;
	char c = 'a';

	while (ii < 6)
	{
		char str[ii];
		strcpy(str, "abc\n");
		jj = 0;
		while (jj < ii)
		{
			test_bzero(str, c, jj, ii);
			jj++;
		}
		strcpy(str, "");
		jj = 0;
		while (jj < ii)
		{
			test_bzero(str, c, jj, ii);
			jj++;
		}
		ii++;
	}
	printf("can be a good job ;)\n");
}



int	ft_isalnum_cmpTest(int argc, char *argv[])
{
	int	ii;

	ii = -1;
	while (ii < 257)
	{
		if (isalnum(ii) != ft_isalnum(ii))
		{
			printf("isalnum(%c) = %d\n", (char)ii, isalnum(ii));
			printf("ft_isalnum(%c) = %d\n", (char)ii, ft_isalnum(ii));
			return (error_msg(ii, "isalnum"));
		}
		ii++;
	}
	(void)argc;
	printf("%s have same output from same input\n", argv[0]);
	return (0);
}


int	ft_isalpha_cmpTest(void)
{
	int	ii;

	ii = -1;
	while (ii < 257)
	{
		if (isalpha(ii) != ft_isalpha(ii))
		{
			printf("isalpha(%c) = %d\n", (char)ii, isalpha(ii));
			printf("ft_isalpha(%c) = %d\n", (char)ii, ft_isalpha(ii));
			return (error_msg(ii, "isalpha"));
		}
		ii++;
	}
	return (0);
}


int	ft_isascii_cmpTest(int argc, char *argv[])
{
	int	ii;

	ii = -1;
	while (ii < 257)
	{
		if (isascii(ii) != ft_isascii(ii))
		{
			printf("isascii(%c) = %d\n", (char)ii, isascii(ii));
			printf("ft_isascii(%c) = %d\n", (char)ii, ft_isascii(ii));
			return (error_msg(ii, "isascii"));
		}
		ii++;
	}
	(void)argc;
	printf("%s have same output from same input\n", argv[0]);
	return (0);
}


int	ft_isdigit_cmpTest(int argc, char *argv[])
{
	int	ii;

	ii = -1;
	while (ii < 257)
	{
		if (isdigit(ii) != ft_isdigit(ii))
		{
			printf("isdigit(%c) = %d\n", (char)ii, isdigit(ii));
			printf("ft_isdigit(%c) = %d\n", (char)ii, ft_isdigit(ii));
			return (error_msg(ii, "isdigit"));
		}
		ii++;
	}
	(void)argc;
	printf("%s have same output from same input\n", argv[0]);
	return (0);
}


int	ft_isprint_cmpTest(int argc, char *argv[])
{
	int	ii;

	ii = -1;
	while (ii < 257)
	{
		if (isprint(ii) != ft_isprint(ii))
		{
			printf("isprint(%c) = %d\n", (char)ii, isprint(ii));
			printf("ft_isprint(%c) = %d\n", (char)ii, ft_isprint(ii));
			return (error_msg(ii, "isprint"));
		}
		ii++;
	}
	(void)argc;
	printf("%s have same output from same input\n", argv[0]);
	return (0);
}


int test_memchr(char *str, char c)
{
	unsigned int	ret;
	int				ii;

	ii = 0;
	while (ii < 5)
	{
		ret = memchr(str, c, ii) - ft_memchr(str, c, ii);
		if (ret)
		{
			printf("[bug] at str: %s, c: %c, n = %d\n", str, c, ii);
			return (1);
		}
		ii++;
	}
	return (0);
}

int	ft_memchr_cmpTest(int argc, char *argv[])
{
	int ii = 0;
	test_memchr("abcbi", 'b');
	test_memchr("abc", '\0');
	test_memchr("", 'a');
	test_memchr("", '\0');
	printf("test finished\n");
}


int test_memcmp(char *s1, char *s2, int len)
{
	int		ii = 0;

	if (ft_memcmp(s1, s2, len) == memcmp(s1, s2, len))
		return (1);
	else
	{
		printf("[BUG]\ns1 = %s, s2 %s\nmemcmp = %d\nft_memcmp = %d\nlen = %d\n\n", s1, s2, memcmp(s1, s2, len), ft_memcmp(s1, s2, len), len);
		return (0);
	}
}

int	ft_memcmp_cmpTest(int argc, char *argv[])
{
	int ii = 0;
	char s1[100];
	char s2[100];
	int ret = 1;

	while (ii < 5)
	{
		strcpy(s1, "abc");
		strcpy(s2, "abc");
		test_memcmp(s1, s2, ii);

		strcpy(s1, "abc");
		strcpy(s2, "");
		test_memcmp(s1, s2, ii);

		strcpy(s1, "");
		strcpy(s2, "abc");
		test_memcmp(s1, s2, ii);

		strcpy(s1, "abz");
		strcpy(s2, "abcfghdfgh");
		test_memcmp(s1, s2, ii);

		strcpy(s1, "abcfghdfgh");
		strcpy(s2, "abz");
		test_memcmp(s1, s2, ii);

		strcpy(s1, "abcfgz");
		strcpy(s2, "abcfghdfgh");
		test_memcmp(s1, s2, ii);

		strcpy(s1, "abcfghdfgh");
		strcpy(s2, "abcfgz");
		test_memcmp(s1, s2, ii);
		ii++;
	}
	printf("can be a good job ;)\n");
}


int test_memcpy(char *to_cpy, int len)
{
	char	s1[1000];
	char	s2[1000];
	int		ii = 0;

	memcpy(s1, to_cpy);
	ft_memcpy(s2, to_cpy);
	while (ii < len)
	{
		if (s1[ii] != s2[ii])
		{
			printf("differents output for str=[%s]\nmemcpy(str) = [%s]\nft_memcpy(str) = [%s]\nlen/str_bufsize = %d\nbuf_size = %d\n", str, s1, s2, len, buf_size);
			printf("\n");
			printf("\n");
			return (1);
		}
		ii++;
	}
	return (0);
}

int	ft_memcpy_cmpTest(int argc, char *argv[])
{
	int ii = 0;

	while (ii < 5)
	{
		char str[ii];
		strcpy(str, "abc\n");
		test_memcpy(str, c, ii);
		ii++;
	}
	ii = 0;
	while (ii < 5)
	{
		char str[ii];
		strcpy(str, "");
		test_memcpy(str, c, ii);
		ii++;
	}
	printf("can be a good job ;)\n");
}


	ii = 0;
	while (ii < n)
	{
		if (s1[ii] == s2[ii]) 
		{
			if (s1[ii] == '\0')
				return (0);
			ii++;
		}
		else
			return (s1[ii] - s2[ii]);
	}
	return (0);
}
	
int test_memmove(int len)
{
	char	s1[] = "0123456789";
	char	s2[] = "0123456789";
	int		ii = 0;

	memmove(s1 + 3, s1 + 2, len);
	ft_memmove(s2 + 3, s2 + 2, len);
	if (ft_strncmp(s1, s2, 1000))
	{
		printf("memmove(str) = [%s]\n\
			ft_memmove(str) = [%s]\n\
			len = %d\n\
			", s1, s2, len);
		printf("\n");
		return (1);
	}
	memmove(s1 + 3, s1 + 2, len);
	ft_memmove(s2 + 3, s2 + 2, len);
	if (ft_strncmp(s1, s2, 1000))
	{
		printf(" memmove(str) = [%s]\n\
			ft_memmove(str) = [%s]\n\
			len = %d\n\
			", s1, s2, len);
		printf("\n");
		return (1);
	}
	memmove(s1 + 3, s1 + 3, len);
	ft_memmove(s2 + 3, s2 + 3, len);
	if (ft_strncmp(s1, s2, 1000))
	{
		printf(" memmove(str) = [%s]\n\
			ft_memmove(str) = [%s]\n\
			len = %d\n\
			", s1, s2, len);
		printf("\n");
		return (1);
	}
	return (0);
}

int	ft_memmove_cmpTest(int argc, char *argv[])
{
	int ii = 0;

	while (ii < 5)
	{
		test_memmove(ii);
		ii++;
	}
	ii = 0;
	while (ii < 6)
	{
		test_memmove(ii);
		ii++;
	}
	printf("can be a good job ;)\n");
}


int test_memset(char *str, int c, int len, int buf_size)
{
	char	s1[1000];
	char	s2[1000];
	int		ii = 0;

	strcpy(s1, str);
	strcpy(s2, str);
	memset(s1, c, len);
	ft_memset(s2, c, len);
	while (ii < len)
	{
		if (s1[ii] != s2[ii])
		{
			printf("differents output for str=[%s]\nmemset(str) = [%s]\nft_memset(str) = [%s]\nlen/str_bufsize = %d\nbuf_size = %d\n", str, s1, s2, len, buf_size);
			printf("\n");
			printf("\n");
			return (1);
		}
		ii++;
	}
	return (0);
}

int	ft_memset_cmpTest(int argc, char *argv[])
{
	int ii = 0;
	int jj = 0;
	char c = 'a';

	while (ii < 6)
	{
		char str[ii];
		strcpy(str, "abc\n");
		jj = 0;
		while (jj < ii)
		{
			test_memset(str, c, jj, ii);
			jj++;
		}
		strcpy(str, "");
		jj = 0;
		while (jj < ii)
		{
			test_memset(str, c, jj, ii);
			jj++;
		}
		ii++;
	}
	printf("can be a good job ;)\n");
}


int test_strchr(char *str, char c)
{
	unsigned int ret;

	ret = strchr(str, c) - ft_strchr(str, c);
	if (ret)
	{
		printf("[bug] at str: %s, c: %c\n", str, c);
		return (1);
	}
	return (0);
}

int	ft_strchr_cmpTest(int argc, char *argv[])
{
	int ii = 0;
	test_strchr("abc", 'b');
	test_strchr("abc", '\0');
	test_strchr("", 'a');
	test_strchr("", '\0');
	printf("test finished\n");
}


int ft_strdup_cmpTest(void)
{
	char *cpy;

	cpy = ft_strdup("La chaine");
	printf("%s\n", cpy);
	free(cpy);
}


int test_strlcat(char *str, char *to_append, int len)
{
	char	*s1;
	char	*s2;
	int		ret;
	int		ii = 0;
	int		jj = 0;

	s1 = malloc(sizeof(char) * (strlen(str) + strlen(to_append) + 2));
	s2 = malloc(sizeof(char) * (strlen(str) + strlen(to_append) + 2));
	strcpy(s1, str);
	strcpy(s2, str);
	strlcat(s1, to_append, len);
	ft_strlcat(s2, to_append, len);
	if ((ret = strncmp(s1, s2, len)))
	{
		printf("Error when len = %d, src = %s, dst = %s\n\
			s1 (   strlcat): [%s]\n\
			s2 (ft_strlcat): [%s]\n\n", len, to_append, str, s1, s2);
		return (0);
	}
	return (1);
}

int	ft_strlcat_cmpTest(int argc, char *argv[])
{
	int ii = 0;
	char s_abc[] = "abc";
	char s_empty[] = "";
	int diff;

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
	printf("can be a good job ;)\n");
}


int test_strlcpy(char *to_cpy, int len)
{
	char	*s1;
	char	*s2;
	int		ii = 0;
	int		jj = 0;

	s1 = malloc(sizeof(char) * 20);
	s2 = malloc(sizeof(char) * 20);
	strlcpy(s1, to_cpy, len);
	ft_strlcpy(s2, to_cpy, len);
	return (strncmp(s1, s2, len));
}

int	ft_strlcpy_cmpTest(int argc, char *argv[])
{
	int ii = 0;

	while (ii < 5)
	{
		test_strlcpy("abc", ii);
		ii++;
	}
	ii = 0;
	while (ii < 2)
	{
		test_strlcpy("", ii);
		ii++;
	}
	printf("can be a good job ;)\n");
}


int test_strlen(char *str, int buf_size)
{
	if (strlen(str) != ft_strlen(str))
	{
		printf("differents output for str=%s\n\t\
			strlen(str) = %lu; ft_strlen(str) = %lu\nbuf_size = %d\n",\
			str, strlen(str), ft_strlen(str), buf_size);
		return (1);
	}
	return (0);
}

int	ft_strlen_cmpTest(int argc, char *argv[])
{
	int ii = 0;

	while (ii < 6)
	{
		char str[ii];
		strcpy(str, "abc\n");
		test_strlen(str, ii);
		strcpy(str, "");
		test_strlen(str, ii);
		ii++;
	}
	printf("can be a good job ;)\n");
}


int test_strncmp(char *s1, char *s2, int len)
{
	int		ii = 0;

	if (ft_strncmp(s1, s2, len) == strncmp(s1, s2, len))
		return (1);
	else
	{
		printf("[BUG]\ns1 = %s, s2 %s\nstrncmp = %d\nft_strncmp = %d\nlen = %d\n\n", s1, s2, strncmp(s1, s2, len), ft_strncmp(s1, s2, len), len);
		return (0);
	}
}

int	ft_strncmp_cmpTest(int argc, char *argv[])
{
	int ii = 0;
	char s1[100];
	char s2[100];
	int ret = 1;

	while (ii < 5)
	{
		strcpy(s1, "abc");
		strcpy(s2, "abc");
		test_strncmp(s1, s2, ii);

		strcpy(s1, "abc");
		strcpy(s2, "");
		test_strncmp(s1, s2, ii);

		strcpy(s1, "");
		strcpy(s2, "abc");
		test_strncmp(s1, s2, ii);

		strcpy(s1, "abz");
		strcpy(s2, "abcfghdfgh");
		test_strncmp(s1, s2, ii);

		strcpy(s1, "abcfghdfgh");
		strcpy(s2, "abz");
		test_strncmp(s1, s2, ii);

		strcpy(s1, "abcfgz");
		strcpy(s2, "abcfghdfgh");
		test_strncmp(s1, s2, ii);

		strcpy(s1, "abcfghdfgh");
		strcpy(s2, "abcfgz");
		test_strncmp(s1, s2, ii);
		ii++;
	}
	printf("can be a good job ;)\n");
}


int test_strnstr(char *haystack, char *needle, unsigned int len)
{
	char *r1, *r2;
	if ((r1 = ft_strnstr(haystack, needle, len)) != (r2 =strnstr(haystack, needle, len)))
	{
		printf("[BUG] strnstr:\n\
			outputs differents when:\n\
			haystack = [%s]; needle = [%s]; len = %d\n\
			ft_strnstr(haystack, needle, len)	= [%s]\n\
		   	strnstr(haystack, needle, len))		= [%s]\n",\
			haystack, needle, len, r1, r2);
	
		return (1);
	}
	return (0);
}

int ft_strnstr_cmpTest(void)
{
	test_strnstr("", "", 0);
	test_strnstr("abc", "", 0);
	test_strnstr("abc", "", 1);
	test_strnstr("", "abc", 1);
	test_strnstr("", "abc", 4);
	test_strnstr("abc", "b", 1);
	test_strnstr("zabcabcd", "abc", 4);
	test_strnstr("abc", "C", 2);
}


int test_strrchr(char *str, char c)
{
	unsigned int ret;

	ret = strrchr(str, c) - ft_strrchr(str, c);
	if (ret)
	{
		printf("[bug] at str: %s, c: %c\n", str, c);
		return (1);
	}
	return (0);
}

int	ft_strrchr_cmpTest(int argc, char *argv[])
{
	int ii = 0;
	test_strrchr("abcbi", 'b');
	test_strrchr("abc", '\0');
	test_strrchr("", 'a');
	test_strrchr("", '\0');
	printf("test finished\n");
}


int	ft_tolower_cmpTest(void)
{
	int	ii;

	ii = -1;
	while (ii < 257)
	{
		if (tolower(ii) != ft_tolower(ii))
		{
			printf("tolower(%c) = %d\n", (char)ii, tolower(ii));
			printf("ft_tolower(%c) = %d\n", (char)ii, ft_tolower(ii));
			return (error_msg(ii, "tolower"));
		}
		ii++;
	}
	printf("You r da man ;)\n");
	return (0);
}


int	ft_toupper_cmpTest(void)
{
	int	ii;

	ii = -1;
	while (ii < 257)
	{
		if (toupper(ii) != ft_toupper(ii))
		{
			printf("toupper(%c) = %d\n", (char)ii, toupper(ii));
			printf("ft_toupper(%c) = %d\n", (char)ii, ft_toupper(ii));
			return (error_msg(ii, "toupper"));
		}
		ii++;
	}
	printf("You r da man ;)\n");
	return (0);
}

int main(void)
{
ft_atoi_cmpTest(void) ;
ft_bzero_cmpTest(void) ;
ft_isalnum_cmpTest(void) ;
ft_isalpha_cmpTest(void) ;
ft_isascii_cmpTest(void) ;
ft_isdigit_cmpTest(void) ;
ft_isprint_cmpTest(void) ;
ft_memchr_cmpTest(void) ;
ft_memcmp_cmpTest(void) ;
ft_memcpy_cmpTest(void) ;
ft_memmove_cmpTest(void) ;
ft_memset_cmpTest(void) ;
ft_strchr_cmpTest(void) ;
ft_strdup_cmpTest(void) ;
ft_strlcat_cmpTest(void) ;
ft_strlcpy_cmpTest(void) ;
ft_strlen_cmpTest(void) ;
ft_strncmp_cmpTest(void) ;
ft_strnstr_cmpTest(void) ;
ft_strrchr_cmpTest(void) ;
ft_tolower_cmpTest(void) ;
ft_toupper_cmpTest(void) ;
}
