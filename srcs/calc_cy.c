#include "minirt.h"

void	cy_calc(t_itrsec *itrsec, t_cylinder *cy, t_ray *ray, double *t)
{
	t_vec	c_to_p[2];
	double	h[2];

	c_to_p[0] = sub(add(ray->start, scalar(ray->dir, t[0], '*')), cy->pos);
	c_to_p[1] = sub(add(ray->start, scalar(ray->dir, t[1], '*')), cy->pos);
	h[0] = dot(c_to_p[0], cy->normal);
	h[1] = dot(c_to_p[1], cy->normal);
	if (h[0] >= 0 && h[0] <= cy->height)
	{
		itrsec->has_itrsec = 1;
		itrsec->normal = normalize(sub(c_to_p[0], \
		scalar(cy->normal, h[0], '*')));
		itrsec->dist = t[0];
		itrsec->pos = add(ray->start, scalar(ray->dir, t[0], '*'));
	}
	else if (h[1] >= 0 && h[1] <= cy->height)
	{
		itrsec->has_itrsec = 1;
		itrsec->normal = normalize(sub(scalar(cy->normal, \
		h[1], '*'), c_to_p[1]));
		itrsec->dist = t[1];
		itrsec->pos = add(ray->start, scalar(ray->dir, t[1], '*'));
	}
	else
		itrsec->has_itrsec = 0;
}

t_itrsec	cylinder_itrsec(t_ray ray, t_cylinder *cy)
{
	t_itrsec	itrsec;
	double		n[4];
	double		t[2];

	n[0] = norm(cross(ray.dir, cy->normal)) * norm(cross(ray.dir, cy->normal));
	n[1] = 2 * dot(cross(ray.dir, cy->normal), \
	cross(sub(ray.start, cy->pos), cy->normal));
	n[2] = norm(cross(sub(ray.start, cy->pos), cy->normal));
	n[2] = n[2] * n[2] - cy->rad * cy->rad;
	n[3] = n[1] * n[1] - 4 * n[0] * n[2];
	if (n[3] < 0)
	{
		itrsec.has_itrsec = 0;
		return (itrsec);
	}
	t[0] = (-n[1] - sqrt(n[3])) / (2 * n[0]);
	t[1] = (-n[1] + sqrt(n[3])) / (2 * n[0]);
	cy_calc(&itrsec, cy, &ray, t);
	return (itrsec);
}
