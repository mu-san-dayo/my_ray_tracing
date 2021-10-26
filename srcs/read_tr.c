#include "minirt.h"

t_shape	*init_triangle(t_vec p1, t_vec p2, t_vec p3, t_material mtrl)
{
	t_shape	*tr;

	tr = malloc(sizeof(t_shape));
	if (tr == NULL)
		return (NULL);
	tr->type = ST_TRIANGLE;
	tr->elem.tr.p1 = p1;
	tr->elem.tr.p2 = p2;
	tr->elem.tr.p3 = p3;
	tr->mtrl = mtrl;
	return (tr);
}

int	set_triangle(t_data *info, char **prm)
{
	t_shape	*shape;
	t_vec	p1;
	t_vec	p2;
	t_vec	p3;
	t_col	col;

	if (ft_row_count((void **)prm) != 4
		|| str_to_vec(&p1, prm[0]) == ERROR
		|| str_to_vec(&p2, prm[1]) == ERROR
		|| str_to_vec(&p3, prm[2]) == ERROR
		|| col_to_bin(&col, prm[3]) == ERROR)
		return (return_error("triangle params error"));
	shape = init_triangle(p1, p2, p3, init_material(col, \
	init_col(0.3, 0.3, 0.3), SHININESS));
	if (!shape || !(ft_lstadd_back_new(&info->shape, shape)))
		return (return_error("Missing malloc"));
	return (0);
}
