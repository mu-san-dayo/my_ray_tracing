#include "minirt.h"

int	valid_path(char *path)
{
	size_t	len;

	len = ft_strlen(path);
	return (!(len < 4 || path[len - 4] == '/'
			|| ft_strncmp(path + len - 3, ".rt", 3)));
}

int	valid_col(int r, int g, int b)
{
	if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255)
		return (0);
	return (1);
}

void	check_prm(t_data *info, char **prm, int *res)
{
	if ((*res >= 0 && prm[0])
		&& (ft_strlen(prm[0]) == 1 && prm[0][0] == 'R'))
		*res = set_resolution(info, prm[1], prm[2], prm + 1);
	else if ((*res >= 0 && prm[0])
		&& (ft_strlen(prm[0]) == 1 && prm[0][0] == 'A'))
		*res = set_ambient(info, prm + 1);
	else if ((*res >= 0 && prm[0])
		&& (ft_strlen(prm[0]) == 1 && prm[0][0] == 'c'))
		*res = set_camera(info, prm + 1);
	else if ((*res >= 0 && prm[0])
		&& (ft_strlen(prm[0]) == 1 && prm[0][0] == 'l'))
		*res = set_light(info, prm + 1);
	else if ((*res >= 0 && prm[0]) && ft_strncmp(prm[0], "sp", 3) == 0)
		*res = set_sphere(info, prm + 1);
	else if ((*res >= 0 && prm[0]) && ft_strncmp(prm[0], "pl", 3) == 0)
		*res = set_plane(info, prm + 1);
	else if ((*res >= 0 && prm[0]) && ft_strncmp(prm[0], "sq", 3) == 0)
		*res = set_square(info, prm + 1);
	else if ((*res >= 0 && prm[0]) && ft_strncmp(prm[0], "tr", 3) == 0)
		*res = set_triangle(info, prm + 1);
	else if ((*res >= 0 && prm[0]) && ft_strncmp(prm[0], "cy", 3) == 0)
		*res = set_cylinder(info, prm + 1);
	else
		*res = other_prm(prm);
}

int	read_file(t_data *info, int fd)
{
	char	*line;
	int		res;
	char	**prm;
	int		gnl;

	res = 0;
	while (res >= 0)
	{
		gnl = get_next_line(fd, &line);
		prm = ft_split(line, ' ');
		if (!prm || gnl == -1)
			res = ERROR;
		check_prm(info, prm, &res);
		free(line);
		line = NULL;
		free_pary((void **)prm);
		if (gnl != 1)
			break ;
	}
	free(line);
	check_base(info, &res);
	return (res);
}

int	read_rt(t_data *info, char *path)
{
	int		fd;

	if (!valid_path(path))
		return (return_error("Missing path"));
	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (return_error("Failed to open rt file"));
	return (read_file(info, fd));
}
