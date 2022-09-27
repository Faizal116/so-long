#include "so_long.h"

static int	press_x(t_program *g)
{
	game_over(g);
	return (0);
}

void	exit_messages(t_program *g)
{
	if (g->lines[g->player1.to.y][g->player1.to.x] == 'E' \
		&& g->player1.c == g->map.coins)
		ft_putstr_fd("Congratulations!\n", 1);
	else if (g->player1.movecount > 99)
		ft_putstr_fd("Map has no valid path\nOr maybe you're just bad ;)\n", 1);
	else 
		ft_putstr_fd("You lose, please try again.\n", 1);
}

void	game_over(t_program *g)
{
	char	**temp;

	exit_messages(g);
	temp = g->lines;
	while (*temp)
		free(*temp++);
	free(g->lines);
	if (g->x1)
		free(g->x1);
	mlx_destroy_image(g->mlx, g->empty);
	mlx_destroy_image(g->mlx, g->coins);
	mlx_destroy_image(g->mlx, g->coins2);
	mlx_destroy_image(g->mlx, g->exit);
	mlx_destroy_image(g->mlx, g->p1);
	mlx_destroy_image(g->mlx, g->p2);
	mlx_destroy_image(g->mlx, g->enemy);
	mlx_clear_window(g->mlx, g->window);
	mlx_destroy_window(g->mlx, g->window);
	free(g->mlx);
	exit (0);
}