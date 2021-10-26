#include "minirt.h"

int	in_the_case_square(t_vec point, t_square *sq)
{
	t_vec		x_basis;
	t_vec		y_basis;
	t_vec		o_p;
	double		x_dist;
	double		y_dist;

	x_basis.x = sq->normal.z / sqrt(sq->normal.z * \
	sq->normal.z + sq->normal.x * sq->normal.x);
	x_basis.y = 0;
	x_basis.z = -sq->normal.x / sqrt(sq->normal.z \
	* sq->normal.z + sq->normal.x * sq->normal.x);
	x_basis = normalize(x_basis);
	y_basis = normalize(cross(x_basis, scalar(sq->normal, -1, '*')));
	o_p = sub(point, sq->center);
	x_dist = dot(o_p, x_basis);
	y_dist = dot(o_p, y_basis);
	if (x_dist >= -sq->side / 2 && x_dist <= sq->side / 2
		&& y_dist >= -sq->side / 2 && y_dist <= sq->side / 2)
		return (1);
	return (0);
}

t_itrsec	square_itrsec(t_ray ray, t_square *sq)
{
	double		d_n_dot;
	t_vec		c_cam;
	double		t;
	t_itrsec	itrsec;

	c_cam = sub(ray.start, sq->center);
	d_n_dot = dot(scalar(ray.dir, -1, '*'), sq->normal);
	if (d_n_dot == 0)
	{
		itrsec.has_itrsec = 0;
		return (itrsec);
	}
	t = dot(c_cam, sq->normal) / d_n_dot;
	itrsec.dist = t;
	if (d_n_dot > 0)
		itrsec.normal = sq->normal;
	else
		itrsec.normal = scalar(sq->normal, -1, '*');
	itrsec.pos = add(ray.start, scalar(ray.dir, t, '*'));
	itrsec.has_itrsec = in_the_case_square(itrsec.pos, sq);
	return (itrsec);
}
