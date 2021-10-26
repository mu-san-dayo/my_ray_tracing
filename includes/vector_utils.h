#ifndef VECTOR_UTILS_H
# define VECTOR_UTILS_H

# include <stdio.h>
# include <math.h>
# include <string.h>

# define ERROR -1
# define SHININESS 30
# define EPSILON 0.000001

typedef struct s_vec
{
	double	x;
	double	y;
	double	z;
}			t_vec;

typedef struct s_col
{
	double	r;
	double	g;
	double	b;
}			t_col;

t_vec	init_vec(double x, double y, double z);
t_col	init_col(double r, double g, double b);

t_vec	add(t_vec a, t_vec b);
t_col	col_add(t_col a, t_col b);
t_vec	sub(t_vec a, t_vec b);
t_vec	mult(t_vec a, t_vec b);
t_col	col_mult(t_col a, t_col b);
t_vec	scalar(t_vec a, double num, char op);
t_col	col_scalar(t_col a, double num, char op);

double	dot(t_vec a, t_vec b);
double	squared_norm(t_vec v);

double	norm(t_vec v);
t_vec	normalize(t_vec v);
t_col	col_norm(t_col col);

t_vec	cross(t_vec a, t_vec b);

#endif
