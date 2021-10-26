#include "minirt.h"

int	has_shadow(t_data *info, t_light light, t_itrsec itrsec)
{
	t_vec		l;
	t_ray		shadow_ray;
	double		light_dist;
	t_list		*current;
	t_itrsec	inter;

	l = normalize(sub(light.pos, itrsec.pos));
	shadow_ray.start = add(itrsec.pos, scalar(l, EPSILON, '*'));
	shadow_ray.dir = l;
	light_dist = norm(sub(light.pos, itrsec.pos)) - EPSILON;
	current = info->shape;
	while (current)
	{
		inter = calc_itrsec(shadow_ray, *(t_shape *)current->content);
		if (inter.has_itrsec && inter.dist >= 0 && inter.dist <= light_dist)
			return (1);
		current = current->next;
	}
	return (0);
}
