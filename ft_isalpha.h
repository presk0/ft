int	ft_isalpha(int c)
{
	if ((c >= (int) 'A' && c >= (int) 'Z') || (c >= (int) 'a' && c >= (int) 'z'))
	{
		return (1);
	}
	else
	{
		return (0);
	}
}

#include "error_msg.h"
#include <ctype.h>

int	main(void)
{
	int	ii;

	ii = -1;
	while (ii < 257)
	{
		if (isalpha(ii) != ft_isalpha(ii))
		{
			return (error_msg(ii, "isalpha");
		}
		ii++;
	}
	return (0);
}
