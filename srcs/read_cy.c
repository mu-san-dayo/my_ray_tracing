#include "minirt.h"

t_shape	*init_cylinder(t_vec pos, t_vec normal, double *f, t_material mtrl)
{
	t_shape	*cy;

	cy = malloc(sizeof(t_shape));
	if (cy == NULL)
		return (NULL);
	cy->type = ST_CYLINDER;
	cy->elem.cy.pos = pos;
	cy->elem.cy.normal = normal;
	cy->elem.cy.rad = f[0];
	cy->elem.cy.height = f[1];
	cy->mtrl = mtrl;
	return (cy);
}

int	set_cylinder(t_data *info, char **prm)
{
	t_shape	*shape;
	t_vec	point;
	t_vec	normal;
	double	f[2];
	t_col	col;

	if (ft_row_count((void **)prm) != 5
		|| str_to_vec(&point, prm[0]) == ERROR
		|| str_to_vec(&normal, prm[1]) == ERROR
		|| col_to_bin(&col, prm[4]) == ERROR)
		return (return_error("Cylinder params error"));
	f[0] = ft_atof(prm[2]) / 2;
	f[1] = ft_atof(prm[3]);
	if (check_normal(&normal) == ERROR)
		return (return_error("Missing normal parameters"));
	shape = init_cylinder(point, normalize(normal), f, \
		init_material(col, init_col(0.3, 0.3, 0.3), SHININESS));
	if (!shape || !(ft_lstadd_back_new(&info->shape, shape)))
		return (return_error("Missing malloc"));
	return (0);
}
