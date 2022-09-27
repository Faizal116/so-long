#include "so_long.h"

void	movement(t_program *g)
{
	char	*mcount;

	if (g->lines[g->player1.to.y][g->player1.to.x] == 'V')
		game_over(g);
	g->lines[g->player1.now.y][g->player1.now.x] = '0';
	enemy_movements(g);
	player_x_coins(g);
	if (g->lines[g->player1.to.y][g->player1.to.x] == 'C')
		g->player1.c += 1;
	else if (g->lines[g->player1.to.y][g->player1.to.x] == 'E' \
			|| g->lines[g->player1.to.y][g->player1.to.x] == 'V')
		game_over(g);
	g->lines[g->player1.to.y][g->player1.to.x] = 'P';
	g->player1.movecount += 1;
	mlx_clear_window(g->mlx, g->window);
	xpm_to_window(g);
	mcount = ft_itoa(g->player1.movecount);
	mlx_string_put(g->mlx, g->window, 12, 22, 0x00FFFFFF, mcount);
	free(mcount);
}

int	key_binding(int pressed, t_program *g)
{
	if (pressed == ESC)
		game_over(g);
	else if (pressed == UP || pressed == DOWN \
				|| pressed == LEFT || pressed == RIGHT)
	{
		if (pressed == UP)
			g->player1.to.y = g->player1.now.y - 1;
		else if (pressed == DOWN)
			g->player1.to.y = g->player1.now.y + 1;
		else if (pressed == LEFT)
			g->player1.to.x = g->player1.now.x - 1;
		else if (pressed == RIGHT)
			g->player1.to.x = g->player1.now.x + 1;
		if (g->lines[g->player1.to.y][g->player1.to.x] != '1')
			movement(g);
		else
		{
			g->player1.to.x = g->player1.now.x;
			g->player1.to.y = g->player1.now.y;
		}
	}
	return (0);
}