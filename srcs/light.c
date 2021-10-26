#include "minirt.h"

t_light	*init_light(t_vec pos, t_col illum)
{
	t_light	*light;

	light = malloc(sizeof(t_light));
	if (light == NULL)
		return (NULL);
	light->pos = pos;
	light->illum = illum;
	return (light);
}

int	set_light(t_data *info, char **prm)
{
	t_light		*light;
	t_vec		pos;
	t_col		col;
	double		illum;

	if (ft_row_count((void **)prm) != 3
		|| str_to_vec(&pos, prm[0]) == ERROR
		|| col_to_bin(&col, prm[2]) == ERROR)
		return (return_error("Light params error"));
	illum = ft_atof(prm[1]);
	col = col_scalar(col, illum, '+');
	light = init_light(pos, col);
	if (!light || !(ft_lstadd_back_new(&info->lights, light)))
		return (return_error("Missing malloc"));
	return (0);
}

double	deg_to_rad(double deg)
{
	return (deg / 180 * M_PI);
}
