#include "minirt.h"

int	in_the_case_triangle(t_vec point, t_triangle *tr)
{
	t_vec	cross_1;
	t_vec	cross_2;
	t_vec	cross_3;
	int		check[3];

	cross_1 = cross(sub(tr->p3, tr->p1), sub(point, tr->p1));
	cross_2 = cross(sub(tr->p1, tr->p2), sub(point, tr->p2));
	cross_3 = cross(sub(tr->p2, tr->p3), sub(point, tr->p3));
	cross_1 = normalize(cross_1);
	cross_2 = normalize(cross_2);
	cross_3 = normalize(cross_3);
	check[0] = dot(cross_1, cross_2) < 0;
	check[1] = dot(cross_2, cross_3) < 0;
	check[2] = dot(cross_3, cross_1) < 0;
	if ((check[0] && check[1] && check[2])
		|| (!check[0] && !check[1] && !check[2]))
		return (1);
	return (0);
}

t_itrsec	triangle_itrsec(t_ray ray, t_triangle *tr)
{
	t_vec		tr_normal;
	double		d_n_dot;
	t_vec		c_cam;
	double		t;
	t_itrsec	itrsec;

	tr_normal = cross(sub(tr->p3, tr->p1), sub(tr->p2, tr->p1));
	tr_normal = normalize(tr_normal);
	c_cam = sub(ray.start, tr->p1);
	d_n_dot = dot(scalar(ray.dir, -1, '*'), tr_normal);
	if (d_n_dot == 0)
	{
		itrsec.has_itrsec = 0;
		return (itrsec);
	}
	t = dot(c_cam, tr_normal) / d_n_dot;
	itrsec.dist = t;
	if (d_n_dot > 0)
		itrsec.normal = tr_normal;
	else
		itrsec.normal = scalar(tr_normal, -1, '*');
	itrsec.pos = add(ray.start, scalar(ray.dir, t, '*'));
	itrsec.has_itrsec = in_the_case_triangle(itrsec.pos, tr);
	return (itrsec);
}
