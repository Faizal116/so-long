#include "so_long.h"

int	main(int ac, char **av)
{
	char		*mcount;
	t_program	g;

	init_game(&g);
	if (ac == 2 && check_map(av[1], &g.map))
	{
		g.mlx = mlx_init();
		g.window = mlx_new_window(g.mlx, g.map.col * g.map.px, \
					g.map.row * g.map.px, "so_long");
		link_xpm(av[1], &g);
		alloc_enemies(&g);
		xpm_to_window(&g);
		mcount = ft_itoa(g.player1.movecount);
		mlx_string_put(g.mlx, g.window, 12, 22, 0x00FFFFFF, mcount);
		free(mcount);
		mlx_hook(g.window, 17, 0, press_x, &g);
		mlx_key_hook(g.window, key_binding, &g);
		mlx_loop_hook(g.mlx, ft_idle_anim, &g);
		mlx_loop(g.mlx);
	}
	else
		ft_putendl_fd("Error", 2);
	return (0);
}