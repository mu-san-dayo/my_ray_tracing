#include "minirt.h"

int	other_prm(char **prm)
{
	if (!prm[0])
		return (0);
	return (-1);
}

void	check_base(t_data *info, int *res)
{
	if (info->r_x == 0 || info->r_y == 0
		|| info->cameras == NULL)
		*res = -1;
	return ;
}

int	check_normal(t_vec *n)
{
	if (n->x < -1.0 || 1.0 < n->x
		|| n->y < -1.0 || 1.0 < n->y
		|| n->z < -1.0 || 1.0 < n->z)
		return (-1);
	return (0);
}
