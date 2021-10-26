#include "minirt.h"

int	main(int argc, char *argv[])
{
	t_data	info;

	info.r_x = 0;
	info.r_y = 0;
	info.cameras = NULL;
	info.shape = NULL;
	info.lights = NULL;
	info.ambient = init_col(-1, -1, -1);
	info.mlx = mlx_init();
	if (argc < 2 || 3 < argc)
		exit_error("Incorrect argments");
	if (read_rt(&info, argv[1]) == -1)
		exit_error("Failed to read the .rt file");
	if (argc == 3)
		save_image(&info, argv[2]);
	if (screen_settings(&info, 1))
		return (1);
	draw_image(&info);
	mlx_hook(info.win, 2, 1, key_press, &info);
	mlx_hook(info.win, HOOK_NUM, 1L << 17, exit_window, &info);
	mlx_loop_hook(info.mlx, &main_loop, &info);
	mlx_loop(info.mlx);
	return (0);
}
