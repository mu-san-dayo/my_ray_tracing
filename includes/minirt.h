#ifndef MINIRT_H
# define MINIRT_H

# if __APPLE__
#  include "../minilibx_mms_20200219/mlx.h"
# elif __linux__
#  include "../minilibx-linux/mlx.h"
# endif

# include "../libft/libft.h"
# include "vector_utils.h"
# include "get_next_line.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdint.h>
# include <stdlib.h>
# include <math.h>
# include <errno.h>
# include <float.h>

# if __APPLE__
#  define KEYCODE_DEL	51
#  define KEYCODE_ESC	53
#  define KEYCODE_LEFT	123
#  define KEYCODE_RIGHT	124
#  define KEYCODE_UP	126
#  define KEYCODE_DOWN	125
#  define KEYCODE_FN	63
#  define KEYCODE_HOME	116
#  define KEYCODE_END	121
#  define KEYCODE_PAGE_UP	115
#  define KEYCODE_PAGE_DOWN	119
#  define HOOK_NUM			17
# elif __linux__
#  define KEYCODE_ESC		0xff1b
#  define KEYCODE_LEFT		0xff51
#  define KEYCODE_RIGHT		0xff53
#  define HOOK_NUM			33
# endif

typedef struct s_sphere
{
	t_vec		center;
	double		rad;
}				t_sphere;

typedef struct s_plane
{
	t_vec		normal;
	t_vec		pos;
}				t_plane;

typedef struct s_square
{
	t_vec		normal;
	t_vec		center;
	double		side;
}				t_square;

typedef struct s_triangle
{
	t_vec		p1;
	t_vec		p2;
	t_vec		p3;
}				t_triangle;

typedef struct s_cylinder
{
	t_vec		pos;
	t_vec		normal;
	double		rad;
	double		height;
}				t_cylinder;

typedef struct s_material
{
	t_col		amb;
	t_col		dif;
	t_col		spe;
	double		shininess;
	int			numbers;
}				t_material;

typedef enum e_shapetype
{
	ST_SPHERE,
	ST_PLANE,
	ST_CYLINDER,
	ST_SQUARE,
	ST_TRIANGLE,
}				t_shapetype;

typedef union u_elem
{
	t_sphere	sp;
	t_plane		pl;
	t_cylinder	cy;
	t_square	sq;
	t_triangle	tr;
}				t_elem;

typedef struct s_shape
{
	t_shapetype	type;
	t_elem		elem;
	t_material	mtrl;
}				t_shape;

typedef struct s_ray
{
	t_vec		start;
	t_vec		dir;
}				t_ray;

typedef struct s_itrsec
{
	int			has_itrsec;
	double		dist;
	t_vec		pos;
	t_vec		normal;
}				t_itrsec;

typedef struct s_light
{
	t_vec		pos;
	t_col		illum;
}				t_light;

typedef struct s_img
{
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	int			width;
	int			height;
}				t_img;

typedef struct s_camera
{
	t_vec			pos;
	t_vec			ori;
	double			fov;
	t_vec			x_basis;
	t_vec			y_basis;
	t_vec			d_center;
	t_img			img;
}					t_camera;

typedef struct s_data
{
	void		*mlx;
	void		*win;
	void		*img;
	char		*addr;
	int			r_x;
	int			r_y;
	int			block_size;
	int			bits_pre_pixel;
	int			line_length;
	int			endian;
	t_dlist		*cameras;
	t_list		*shape;
	t_col		ambient;
	t_list		*lights;
}				t_data;

unsigned int	rgb_to_hex(int r, int g, int b);
unsigned int	col_to_hex(t_col col);
int				set_ambient(t_data *info, char **prm);

void			cy_calc(t_itrsec *itrsec, t_cylinder *cy, t_ray *ray, \
				double *t);
t_itrsec		cylinder_itrsec(t_ray ray, t_cylinder *cy);

t_itrsec		plane_itrsec(t_ray ray, t_plane *pl);

void			sp_calc(t_itrsec *itrsec, double t, t_sphere *sp, t_ray *ray);
t_itrsec		sphere_itrsec(t_ray ray, t_sphere *sp);

int				in_the_case_square(t_vec point, t_square *sq);
t_itrsec		square_itrsec(t_ray ray, t_square *sq);

int				in_the_case_triangle(t_vec point, t_triangle *tr);
t_itrsec		triangle_itrsec(t_ray ray, t_triangle *tr);

t_camera		*camera_setup(t_data *info, t_vec pos, t_vec ori, double fov);
void			camera_basis(t_camera *camera);
t_camera		*init_camera(t_data *info, t_vec pos, t_vec ori, double fov);
int				set_camera(t_data *info, char **prm);

t_col			init_col(double r, double g, double b);
t_col			col_add(t_col a, t_col b);
t_col			col_mult(t_col a, t_col b);
t_col			col_scalar(t_col a, double num, char op);
t_col			col_norm(t_col col);

size_t			gnl_strlen(char *str);
size_t			gnl_strchar(char *s, char c);
char			*gnl_strnjoin(char *s1, char *s2, size_t n2);
char			*gnl_strdup(char *s1);

int				find_newline(int fd, char **line, char **sv, char *buf);
int				get_next_line(int fd, char **line);
int				gnl_free_all(char **line, char **sv, int fd);

int				key_press(int key, t_data *info);
int				exit_window(t_data *info);
int				rgb_to_color(int r, int g, int b);
void			my_mlx_pixel_put(t_img *img, int x, int y, int color);
unsigned int	get_color_from_img(t_img img, int x, int y);

t_light			*init_light(t_vec pos, t_col illum);
int				set_light(t_data *info, char **prm);
double			deg_to_rad(double deg);

t_col			calc_ref_diff(t_shape shape, t_itrsec itrsec, t_light light);
t_col			calc_ref_spec(t_ray ray, t_shape shape, t_itrsec itrsec, \
				t_light light);
void			calc_ray(t_data *info, t_ray *ray, t_shape *nearest, \
				t_col *result);

t_itrsec		calc_itrsec(t_ray ray, t_shape shape);
t_shape			*get_nearest(t_data *info, t_ray ray);
void			raytrace(t_data *info, t_camera *camera, int x, int y);
void			draw_image(t_data *info);

t_shape			*init_cylinder(t_vec pos, t_vec normal, double *f, \
				t_material mtrl);
int				set_cylinder(t_data *info, char **prm);

t_shape			*init_plane(t_vec pos, t_vec normal, t_material mtrl);
int				set_plane(t_data *info, char **prm);

int				valid_path(char *path);
int				valid_col(int r, int g, int b);
void			check_prm(t_data *info, char **prm, int *res);
int				read_file(t_data *info, int fd);
int				read_rt(t_data *info, char *path);

t_shape			*init_sphere(t_vec center, double rad, t_material mtrl);
int				set_sphere(t_data *info, char **prm);

t_shape			*init_square(t_vec center, t_vec normal, double side_size, \
				t_material mtrl);
int				set_square(t_data *info, char **prm);

t_shape			*init_triangle(t_vec p1, t_vec p2, t_vec p3, t_material mtrl);
int				set_triangle(t_data *info, char **prm);

int				get_rgbhex_from_rgbstr(unsigned int *col, char *rgbstr);
int				col_to_bin(t_col *col, char *rgbstr);
int				str_to_vec(t_vec *vec, char *str);
t_material		init_material(t_col diffuse, t_col specular, double shininess);
void			free_pary(void **pary);

int				str_check(char *str);
int				set_resolution(t_data *info, char *width_str, \
				char *height_str, char **prm);

void			write_image_data(t_img *img, int fd);
int				write_camera2bmp(t_camera *camera, char *fpath);
int				write_world2bmp(t_data *info);
int				save_image(t_data *info, char *s);

int				has_shadow(t_data *info, t_light light, t_itrsec itrsec);

t_vec			init_vec(double x, double y, double z);
t_vec			add(t_vec a, t_vec b);
t_vec			sub(t_vec a, t_vec b);
t_vec			mult(t_vec a, t_vec b);
t_vec			scalar(t_vec a, double num, char op);

double			dot(t_vec a, t_vec b);
double			squared_norm(t_vec v);
double			norm(t_vec v);
t_vec			normalize(t_vec v);
t_vec			cross(t_vec a, t_vec b);

int				window_settings(t_data *info);
int				screen_settings(t_data *info, int check);
int				main_loop(t_data *world);
void			write_file_header(t_img *img, int fd);
void			write_information_header(t_img *img, int fd);
int				i_min(int a, int b);
int				i_max(int a, int b);
double			f_sqr(double x);

int				get_split_size(char *str, char c);
size_t			strccount(char *str, char c);

int				return_error(char *str);
int				exit_error(char *str);

int				other_prm(char **prm);
void			check_base(t_data *info, int *res);
int				check_normal(t_vec *n);

#endif