#include "minirt.h"

t_itrsec	calc_itrsec(t_ray ray, t_shape shape)
{
	if (shape.type == ST_PLANE)
		return (plane_itrsec(ray, &shape.elem.pl));
	else if (shape.type == ST_SPHERE)
		return (sphere_itrsec(ray, &shape.elem.sp));
	else if (shape.type == ST_TRIANGLE)
		return (triangle_itrsec(ray, &shape.elem.tr));
	else if (shape.type == ST_SQUARE)
		return (square_itrsec(ray, &shape.elem.sq));
	else //(shape.type == ST_CYLINDER)
		return (cylinder_itrsec(ray, &shape.elem.cy));
}

t_shape	*get_nearest(t_data *info, t_ray ray)
{
	t_shape		*nearest;
	t_shape		*current;
	double		n_dist;
	t_list		*current_lst;
	t_itrsec	itrsec;

	n_dist = INFINITY;
	nearest = NULL;
	current_lst = info->shape;
	while (current_lst)
	{
		current = (t_shape *)current_lst->content;
		itrsec = calc_itrsec(ray, *current);
		if (itrsec.has_itrsec)
		{
			if (itrsec.dist >= 0 && itrsec.dist <= n_dist)
			{
				nearest = current;
				n_dist = itrsec.dist;
			}
		}
		current_lst = current_lst->next;
	}
	return (nearest);
}

void	raytrace(t_data *info, t_camera *camera, int x, int y)
{
	t_ray	ray;
	t_shape	*nearest;
	t_col	result;

	ray.dir = normalize(add(camera->d_center, add(scalar(camera->x_basis, \
		(x - (info->r_x - 1) / 2), '*'), scalar(camera->y_basis, \
		((info->r_y - 1) / 2 - y), '*'))));
	ray.start = camera->pos;
	nearest = get_nearest(info, ray);
	if (nearest)
	{
		calc_ray(info, &ray, nearest, &result);
		my_mlx_pixel_put(&camera->img, x, y, col_to_hex(result));
	}
	else
		my_mlx_pixel_put(&camera->img, x, y, rgb_to_color(0, 0, 0));
}

void	draw_image(t_data *info)
{
	t_dlist		*first_camera;
	t_camera	*camera;
	int			y;
	int			x;

	first_camera = info->cameras;
	while (1)
	{
		camera = (t_camera *)info->cameras->elem;
		printf("%lf %lf %lf\n", camera->pos.x, camera->pos.y, camera->pos.z);
		y = 0;
		while (y < info->r_y)
		{
			x = -1;
			while (++x < info->r_x)
				raytrace(info, camera, x, y);
			y++;
		}
		info->cameras = info->cameras->next;
		if (info->cameras == first_camera)
			break ;
	}
}
