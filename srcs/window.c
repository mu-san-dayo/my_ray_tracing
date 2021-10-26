#include "minirt.h"

int	window_settings(t_data *info)
{
	int	max_width;
	int	max_height;

	mlx_get_screen_size(info->mlx, &max_width, &max_height);
	info->r_x = i_min(info->r_x, max_width);
	info->r_y = i_min(info->r_y, max_height);
	info->win = mlx_new_window(info->mlx, info->r_x, info->r_y, "miniRT");
	if (!info->win)
		return (return_error("Failed to create window"));
	return (0);
}

int	screen_settings(t_data *info, int check)
{
	if (check && window_settings(info) == ERROR)
		return (ERROR);
	return (0);
}

int	main_loop(t_data *world)
{
	t_camera	*camera;

	camera = (t_camera *)world->cameras->elem;
	mlx_put_image_to_window(world->mlx, world->win, camera->img.img, 0, 0);
	return (0);
}

void	write_file_header(t_img *img, int fd)
{
	unsigned int	tmp;

	write(fd, "BM", 2);
	tmp = 14 + 10 + img->width * img->height * 4;
	write(fd, &tmp, 4);
	write(fd, "\0\0", 2);
	write(fd, "\0\0", 2);
	tmp = 14 + 10;
	write(fd, &tmp, 4);
}

void	write_information_header(t_img *img, int fd)
{
	unsigned int	tmp;

	tmp = 12;
	write(fd, &tmp, 4);
	write(fd, &img->width, 2);
	write(fd, &img->height, 2);
	tmp = 1;
	write(fd, &tmp, 2);
	tmp = 32;
	write(fd, &tmp, 2);
}
