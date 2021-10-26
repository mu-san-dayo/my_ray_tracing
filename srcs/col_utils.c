#include "vector_utils.h"

t_col	init_col(double r, double g, double b)
{
	t_col	res;

	res.r = r;
	res.g = g;
	res.b = b;
	return (res);
}

t_col	col_add(t_col a, t_col b)
{
	t_col	res;

	res.r = a.r + b.r;
	res.g = a.g + b.g;
	res.b = a.b + b.b;
	return (col_norm(res));
}

t_col	col_mult(t_col a, t_col b)
{
	a.r *= b.r;
	a.g *= b.g;
	a.b *= b.b;
	return (col_norm(a));
}

t_col	col_scalar(t_col a, double num, char op)
{
	if (op == '*')
	{
		a.r = a.r * num;
		a.g = a.g * num;
		a.b = a.b * num;
	}
	else if (op == '+')
	{
		a.r = a.r + num;
		a.g = a.g + num;
		a.b = a.b + num;
	}
	return (a);
}

t_col	col_norm(t_col col)
{
	if (col.r < 0)
		col.r = 0.0;
	if (col.g < 0)
		col.g = 0.0;
	if (col.b < 0)
		col.b = 0.0;
	if (col.r > 1.0)
		col.r = 1.0;
	if (col.g > 1.0)
		col.g = 1.0;
	if (col.b > 1.0)
		col.b = 1.0;
	return (col);
}
