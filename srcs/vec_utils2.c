#include "vector_utils.h"

t_vec	init_vec(double x, double y, double z)
{
	t_vec	res;

	res.x = x;
	res.y = y;
	res.z = z;
	return (res);
}

t_vec	add(t_vec a, t_vec b)
{
	t_vec	res;

	res.x = a.x + b.x;
	res.y = a.y + b.y;
	res.z = a.z + b.z;
	return (res);
}

t_vec	sub(t_vec a, t_vec b)
{
	t_vec	res;

	res.x = a.x - b.x;
	res.y = a.y - b.y;
	res.z = a.z - b.z;
	return (res);
}

t_vec	mult(t_vec a, t_vec b)
{
	t_vec	res;

	res.x = a.x * b.x;
	res.y = a.y * b.y;
	res.z = a.z * b.z;
	return (res);
}

t_vec	scalar(t_vec a, double num, char op)
{
	t_vec	res;

	if (op == '*')
	{
		res.x = a.x * num;
		res.y = a.y * num;
		res.z = a.z * num;
	}
	else if (op == '+')
	{
		res.x = a.x + num;
		res.y = a.y + num;
		res.z = a.z + num;
	}
	return (res);
}
