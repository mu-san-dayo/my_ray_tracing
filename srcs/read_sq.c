#include "minirt.h"

t_shape	*init_square(t_vec center, t_vec normal, double side_size,
	t_material mtrl)
{
	t_shape	*sq;

	sq = malloc(sizeof(t_shape));
	if (sq == NULL)
		return (NULL);
	sq->type = ST_SQUARE;
	sq->elem.sq.center = center;
	sq->elem.sq.normal = normal;
	sq->elem.sq.side = side_size;
	sq->mtrl = mtrl;
	return (sq);
}

int	set_square(t_data *info, char **prm)
{
	t_shape	*shape;
	t_vec	point;
	double	side_size;
	t_vec	normal;
	t_col	col;

	if (ft_row_count((void **)prm) != 4
		|| str_to_vec(&point, prm[0]) == ERROR
		|| str_to_vec(&normal, prm[1]) == ERROR
		|| col_to_bin(&col, prm[3]) == ERROR)
		return (return_error("Square params error"));
	if (check_normal(&normal) == ERROR)
		return (return_error("Missing normal parameters"));
	side_size = ft_atof(prm[2]);
	shape = init_square(point, normalize(normal), side_size, \
		init_material(col, init_col(0.3, 0.3, 0.3), SHININESS));
	if (!shape || !(ft_lstadd_back_new(&info->shape, shape)))
		return (return_error("Missing malloc"));
	return (0);
}
