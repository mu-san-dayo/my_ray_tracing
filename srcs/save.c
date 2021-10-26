#include "minirt.h"

void	write_image_data(t_img *img, int fd)
{
	unsigned int	tmp;
	int				x;
	int				y;

	y = img->height - 1;
	while (y >= 0)
	{
		x = 0;
		while (x < img->width)
		{
			tmp = get_color_from_img(*img, x, y);
			write(fd, &tmp, 4);
			x++;
		}
		y--;
	}
}

int	write_camera2bmp(t_camera *camera, char *fpath)
{
	int	fd;

	fd = open(fpath, O_WRONLY | O_CREAT, S_IRWXU | S_IRWXG | S_IRWXO);
	if (fd == -1)
		return (-1);
	write_file_header(&camera->img, fd);
	write_information_header(&camera->img, fd);
	write_image_data(&camera->img, fd);
	close(fd);
	return (0);
}

int	write_world2bmp(t_data *info)
{
	t_dlist		*first_camera;
	t_camera	*camera;
	char		*filepath;
	int			idx;

	first_camera = info->cameras;
	idx = 0;
	while (1)
	{
		camera = (t_camera *)info->cameras->elem;
		filepath = ft_strjoin(ft_itoa(idx), "cam.bmp");
		write_camera2bmp(camera, filepath);
		printf("DONE writing bmp file %s\n", filepath);
		free(filepath);
		info->cameras = info->cameras->next;
		idx++;
		if (info->cameras == first_camera)
			break ;
	}
	printf("DONE writing all bmp files\n");
	return (0);
}

int	save_image(t_data *info, char *s)
{
	if (ft_strncmp(s, "--save", ft_strlen("--save") + 1))
		return (exit_error("Failed save"));
	if (screen_settings(info, 0))
		exit (1);
	draw_image(info);
	write_world2bmp(info);
	exit(0);
}
