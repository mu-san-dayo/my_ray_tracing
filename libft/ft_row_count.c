#include "libft.h"

size_t	ft_row_count(void **pstr)
{
	size_t	i;

	i = 0;
	while (pstr[i])
		i++;
	return (i);
}
