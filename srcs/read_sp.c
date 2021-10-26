#include "minirt.h"

t_shape	*init_sphere(t_vec center, double rad, t_material mtrl)
{
	t_shape	*sp;

	sp = malloc(sizeof(t_shape));
	if (sp == NULL)
		return (NULL);
	sp->type = ST_SPHERE;
	sp->elem.sp.center = center;
	sp->elem.sp.rad = rad;
	sp->mtrl = mtrl;
	return (sp);
}

int	set_sphere(t_data *info, char **prm)
{
	t_shape	*shape;
	t_vec	pos;
	double	diameter;
	t_col	col;

	if (ft_row_count((void **)prm) != 3
		|| str_to_vec(&pos, prm[0]) == ERROR
		|| col_to_bin(&col, prm[2]) == ERROR)
		return (return_error("Sphere params error"));
	diameter = ft_atof(prm[1]);
	shape = init_sphere(pos, diameter / 2, init_material(col, \
		init_col(0.9, 0.9, 0.9), SHININESS));
	if (!shape || !(ft_lstadd_back_new(&info->shape, shape)))
		return (return_error("Missing malloc"));
	return (0);
}
