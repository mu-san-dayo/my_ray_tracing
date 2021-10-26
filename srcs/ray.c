#include "minirt.h"

t_col	calc_ref_diff(t_shape shape, t_itrsec itrsec, t_light light)
{
	t_vec	l;
	double	ray_deg;
	t_col	ref_diff;

	l = normalize(sub(light.pos, itrsec.pos));
	ray_deg = dot(itrsec.normal, l);
	if (ray_deg < 0)
		ray_deg = 0;
	ref_diff = col_scalar(col_mult(shape.mtrl.dif, light.illum), ray_deg, '*');
	return (ref_diff);
}

t_col	calc_ref_spec(t_ray ray, t_shape shape, t_itrsec itrsec, t_light light)
{
	t_vec	l;
	t_vec	v;
	t_vec	r;
	t_col	ref_spec;

	l = normalize(sub(light.pos, itrsec.pos));
	v = scalar(ray.dir, -1, '*');
	r = sub(scalar(scalar(itrsec.normal, dot(itrsec.normal, l), '*'), \
		2, '*'), l);
	ref_spec = col_scalar(col_mult(shape.mtrl.spe, light.illum), \
		pow(dot(v, r), shape.mtrl.shininess), '*');
	if (dot(v, r) < 0)
		ref_spec = init_col(0, 0, 0);
	return (ref_spec);
}

void	calc_ray(t_data *info, t_ray *ray, t_shape *nearest, t_col *result)
{
	t_itrsec	itrsec;
	t_list		*current_light;
	t_col		ref_diff_spec;
	t_col		res;

	itrsec = calc_itrsec(*ray, *nearest);
	current_light = info->lights;
	ref_diff_spec = init_col(0, 0, 0);
	if (itrsec.dist < 0)
		return ;
	while (current_light)
	{
		res = col_add(calc_ref_diff(*nearest, \
			itrsec, *(t_light *)current_light->content), calc_ref_spec(*ray, \
			*nearest, itrsec, *(t_light *)current_light->content));
		if (has_shadow(info, *(t_light *)current_light->content, itrsec))
			res = init_col(0, 0, 0);
		ref_diff_spec = col_add(ref_diff_spec, res);
		current_light = current_light->next;
	}
	*result = col_add(col_mult(nearest->mtrl.dif, info->ambient), \
		ref_diff_spec);
}
