#include "minirt.h"

int	str_check(char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int	set_resolution(t_data *info, char *width_str, char *height_str, char **prm)
{
	int	width;
	int	height;

	if (ft_row_count((void **)prm) != 2)
		return (return_error("Missing Resolution"));
	if (info->r_x || info->r_y)
		return (return_error("Resolution is already defined"));
	if (!str_check(width_str) || !str_check(height_str))
		return (return_error("Missing Resolution"));
	width = ft_atoi(width_str);
	height = ft_atoi(height_str);
	if ((width_str[0] == '0' && width) || (height_str[0] == '0' && height)
		|| width <= 0 || height <= 0)
		return (return_error("Missing Resolution"));
	if (5000 <= width || 5000 <= height)
		return (return_error("Too large resolution params"));
	info->r_x = width;
	info->r_y = height;
	return (0);
}
