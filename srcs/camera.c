#include "minirt.h"

t_camera	*camera_setup(t_data *info, t_vec pos, t_vec ori, double fov)
{
	t_camera	*camera;
	double		d;

	camera = malloc(sizeof(t_camera));
	if (camera == NULL)
		return (NULL);
	camera->pos = pos;
	camera->ori = ori;
	camera->fov = fov;
	camera->img.img = mlx_new_image(info->mlx,
			info->r_x, info->r_y);
	camera->img.addr = mlx_get_data_addr(camera->img.img,
			&camera->img.bits_per_pixel,
			&camera->img.line_length, &camera->img.endian);
	camera->img.width = info->r_x;
	camera->img.height = info->r_y;
	d = info->r_x / 2 / tan(deg_to_rad(camera->fov / 2));
	camera->d_center = scalar(camera->ori, d, '*');
	return (camera);
}

void	camera_basis(t_camera *camera)
{
	t_vec	x_basis;
	t_vec	y_basis;

	x_basis.x = camera->d_center.z / sqrt(camera->d_center.z \
		* camera->d_center.z + camera->d_center.x * camera->d_center.x);
	x_basis.y = 0;
	x_basis.z = -camera->d_center.x / sqrt(camera->d_center.z \
		* camera->d_center.z + camera->d_center.x * camera->d_center.x);
	y_basis = normalize(cross(x_basis, scalar(camera->d_center, -1, '*')));
	if (camera->ori.x == 0 && camera->ori.y != 0 && camera->ori.z == 0)
	{
		if (camera->ori.y > 0)
		{
			x_basis = init_vec(-1, 0, 0);
			y_basis = init_vec(0, 0, -1);
		}
		else
		{
			x_basis = init_vec(1, 0, 0);
			y_basis = init_vec(0, 0, 1);
		}
	}
	camera->x_basis = x_basis;
	camera->y_basis = y_basis;
}

t_camera	*init_camera(t_data *info, t_vec pos, t_vec ori, double fov)
{
	t_camera	*camera;

	camera = camera_setup(info, pos, ori, fov);
	camera_basis(camera);
	return (camera);
}

int	set_camera(t_data	*info, char	**prm)
{
	t_vec		pos;
	t_vec		ori;
	double		fov;
	t_camera	*camera;

	if (info->r_x == 0 || info->r_y == 0)
		return (return_error("Nothing resolution"));
	if (ft_row_count((void **)prm) != 3
		|| str_to_vec(&pos, prm[0]) == ERROR
		|| str_to_vec(&ori, prm[1]) == ERROR)
		return (return_error("Camera params error"));
	if (check_normal(&ori) == ERROR)
		return (return_error("Missing normal parameters"));
	fov = ft_atof(prm[2]);
	camera = init_camera(info, pos, normalize(ori), fov);
	if (!camera
		|| !(ft_dlst_elem_new(&info->cameras, (void *)camera)))
		return (return_error("Missing malloc"));
	return (0);
}
