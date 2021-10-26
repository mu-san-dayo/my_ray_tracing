#include "minirt.h"

int	i_min(int a, int b)
{
	int	res;

	if (a < b)
		res = a;
	else
		res = b;
	return (res);
}

int	i_max(int a, int b)
{
	int	res;

	if (a > b)
		res = a;
	else
		res = b;
	return (res);
}

double	f_sqr(double x)
{
	return (x * x);
}
