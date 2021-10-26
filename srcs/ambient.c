#include "minirt.h"

unsigned int	rgb_to_hex(int r, int g, int b)
{
	unsigned int	col;

	col = 0;
	col |= b;
	col |= g << 8;
	col |= r << 16;
	return (col);
}

unsigned int	col_to_hex(t_col col)
{
	return (rgb_to_hex(col.r * 255, col.g * 255, col.b * 255));
}

int	set_ambient(t_data *info, char **prm)
{
	t_col	col;
	double	illum;
	size_t	i;

	if (info->ambient.r != -1 || info->ambient.g != -1 \
		|| info->ambient.b != -1)
		return (return_error("Ambient is already defined"));
	i = 0;
	while (prm[i])
		i++;
	if (i != 2)
		return (return_error("Ambient params error"));
	illum = ft_atof(prm[0]);
	if (col_to_bin(&col, prm[1]) == ERROR)
		return (return_error("Ambient params error"));
	info->ambient = col_scalar(col, illum, '*');
	return (0);
}
