#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
	char *s = malloc(100);
	
	strcpy(s, "une chaine");
	while ('a' != *(++s))
		printf("%c\n", *s);
}
