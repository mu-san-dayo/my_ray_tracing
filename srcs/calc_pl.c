#include "minirt.h"

t_itrsec	plane_itrsec(t_ray ray, t_plane *pl)
{
	double		d_n_dot;
	t_vec		c_cam;
	double		t;
	t_itrsec	itrsec;

	c_cam = sub(ray.start, pl->pos);
	d_n_dot = dot(scalar(ray.dir, -1, '*'), pl->normal);
	if (d_n_dot == 0)
	{
		itrsec.has_itrsec = 0;
		return (itrsec);
	}
	t = dot(c_cam, pl->normal) / d_n_dot;
	itrsec.has_itrsec = 1;
	itrsec.dist = t;
	if (d_n_dot > 0)
		itrsec.normal = pl->normal;
	else
		itrsec.normal = scalar(pl->normal, -1, '*');
	itrsec.pos = add(ray.start, scalar(ray.dir, t, '*'));
	return (itrsec);
}
