#include "minirt.h"

t_shape	*init_plane(t_vec pos, t_vec normal, t_material mtrl)
{
	t_shape	*pl;

	pl = malloc(sizeof(t_shape));
	if (pl == NULL)
		return (NULL);
	pl->type = ST_PLANE;
	pl->elem.pl.pos = pos;
	pl->elem.pl.normal = normal;
	pl->mtrl = mtrl;
	return (pl);
}

int	set_plane(t_data *info, char **prm)
{
	t_shape	*shape;
	t_vec	pos;
	t_vec	normal;
	t_col	col;

	if (ft_row_count((void **)prm) != 3
		|| str_to_vec(&pos, prm[0]) == ERROR
		|| str_to_vec(&normal, prm[1]) == ERROR
		|| col_to_bin(&col, prm[2]) == ERROR)
		return (return_error("Plane params error"));
	if (check_normal(&normal) == ERROR)
		return (return_error("Missing normal parameters"));
	shape = init_plane(pos, normalize(normal), \
		init_material(col, init_col(0.3, 0.3, 0.3), SHININESS));
	if (!shape || !(ft_lstadd_back_new(&info->shape, shape)))
		return (return_error("Missing malloc"));
	return (0);
}
