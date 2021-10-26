#include "minirt.h"

int	get_rgbhex_from_rgbstr(unsigned int *col, char *rgbstr)
{
	char	**rgb;

	if (strccount(rgbstr, ',') != 2 || get_split_size(rgbstr, ',') != 3)
		return (return_error("Invalid rgb params error"));
	rgb = ft_split(rgbstr, ',');
	if (!rgb)
		return (ERROR);
	if (!str_check(rgb[0]) || !str_check(rgb[1]) || !str_check(rgb[2])
		|| !valid_col(ft_atoi(rgb[0]), ft_atoi(rgb[1]), ft_atoi(rgb[2]))
		|| (rgb[0][0] == '0' && rgb[0][1])
		|| (rgb[1][0] == '0' && rgb[1][1])
		|| (rgb[2][0] == '0' && rgb[2][1]))
	{
		free_pary((void **)rgb);
		return (ERROR);
	}
	*col = 0;
	*col = ft_atoi(rgb[0]) << 16 | ft_atoi(rgb[1]) << 8 | ft_atoi(rgb[2]);
	free_pary((void **)rgb);
	return (0);
}

int	col_to_bin(t_col *col, char *rgbstr)
{
	unsigned int	rgbhex;
	double			r;
	double			g;
	double			b;

	if (get_rgbhex_from_rgbstr(&rgbhex, rgbstr) == ERROR)
		return (return_error("Missing rgbstr to color"));
	r = (double)(rgbhex >> 16 & 0xff) / 255;
	g = (double)(rgbhex >> 8 & 0xff) / 255;
	b = (double)(rgbhex & 0xff) / 255;
	*col = col_norm(init_col(r, g, b));
	return (0);
}

int	str_to_vec(t_vec *vec, char *str)
{
	char	**vec_mtrl;

	vec_mtrl = ft_split(str, ',');
	if (vec_mtrl == NULL || strccount(str, ',') != 2
		|| ft_row_count((void **)vec_mtrl) != 3)
	{
		printf("input str: %s\n", str);
		free_pary((void **)vec_mtrl);
		return (return_error("failed string to vector"));
	}
	vec->x = ft_atof(vec_mtrl[0]);
	vec->y = ft_atof(vec_mtrl[1]);
	vec->z = ft_atof(vec_mtrl[2]);
	free_pary((void **)vec_mtrl);
	return (0);
}

t_material	init_material(t_col diffuse, t_col specular, double shininess)
{
	t_material	mtrl;

	mtrl.dif = diffuse;
	mtrl.spe = specular;
	mtrl.shininess = shininess;
	return (mtrl);
}

void	free_pary(void **pary)
{
	size_t	i;

	i = 0;
	while (pary[i])
	{
		free(pary[i]);
		pary[i++] = NULL;
	}
	free(pary);
}
