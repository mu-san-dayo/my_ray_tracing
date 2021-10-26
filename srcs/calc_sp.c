#include "minirt.h"

void	sp_calc(t_itrsec *itrsec, double t, t_sphere *sp, t_ray *ray)
{
	t_vec	p_i;
	t_vec	normal;

	p_i = add(ray->start, scalar(ray->dir, t, '*'));
	normal = normalize(sub(p_i, sp->center));
	itrsec->has_itrsec = 1;
	itrsec->dist = t;
	itrsec->normal = normal;
	itrsec->pos = p_i;
}

t_itrsec	sphere_itrsec(t_ray ray, t_sphere *sp)
{
	t_vec		sp_cam;
	double		n[4];
	t_itrsec	itrsec;
	double		t;

	sp_cam = sub(ray.start, sp->center);
	n[0] = norm(ray.dir) * norm(ray.dir);
	n[1] = 2 * dot(sp_cam, ray.dir);
	n[2] = dot(sp_cam, sp_cam) - sp->rad * sp->rad;
	n[3] = n[1] * n[1] - 4 * n[0] * n[2];
	if (n[3] < 0)
	{
		itrsec.has_itrsec = 0;
		return (itrsec);
	}
	t = (-n[1] - sqrt(n[3])) / (2 * n[0]);
	sp_calc(&itrsec, t, sp, &ray);
	return (itrsec);
}
