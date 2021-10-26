#include "vector_utils.h"

double	dot(t_vec a, t_vec b)
{
	return (a.x * b.x + a.y * b.y + a.z * b.z);
}

double	squared_norm(t_vec v)
{
	return (v.x * v.x + v.y * v.y + v.z * v.z);
}

double	norm(t_vec v)
{
	return (sqrt(squared_norm(v)));
}

t_vec	normalize(t_vec v)
{
	t_vec	res;
	double	vnorm;

	vnorm = norm(v);
	res.x = v.x / vnorm;
	res.y = v.y / vnorm;
	res.z = v.z / vnorm;
	return (res);
}

t_vec	cross(t_vec a, t_vec b)
{
	t_vec	o;

	o.x = a.y * b.z - a.z * b.y;
	o.y = a.z * b.x - a.x * b.z;
	o.z = a.x * b.y - a.y * b.x;
	return (o);
}
