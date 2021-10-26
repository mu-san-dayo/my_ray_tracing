#include "minirt.h"

int	key_press(int key, t_data *info)
{
	if (key == KEYCODE_ESC)
	{
		mlx_destroy_window(info->mlx, info->win);
		exit(0);
	}
	if (key == KEYCODE_LEFT)
		if (info->cameras)
			info->cameras = info->cameras->next;
	if (key == KEYCODE_RIGHT)
		if (info->cameras)
			info->cameras = info->cameras->prev;
	return (0);
}

int	exit_window(t_data *info)
{
	if (info->mlx && info->win)
		mlx_destroy_window(info->mlx, info->win);
	if (info->mlx)
		mlx_destroy_display(info->mlx);
	exit(0);
}

int	rgb_to_color(int r, int g, int b)
{
	r = i_max(0, i_min(r, 255));
	g = i_max(0, i_min(g, 255));
	b = i_max(0, i_min(b, 255));
	return (r << 16 | g << 8 | b);
}

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length
			+ x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

unsigned int	get_color_from_img(t_img img, int x, int y)
{
	return (*(unsigned int *)(img.addr
		+ (y * img.line_length + x * (img.bits_per_pixel / 8))));
}
