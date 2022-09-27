#include "so_long.h"

static void	player_x_coins(t_program *g)
{
	void	*temp;

	temp = g->coins;
	g->coins = g->coins2;
	g->coins2 = temp;
	if (g->lines[g->player1.to.y][g->player1.to.x] == 'C')
		g->p = g->p2;
	else
		g->p = g->p1;
}

//animates by using swap to swap the images of the coins to imitate rotating movement
//player changes image when it collects a coin to show golden tinge on some parts by also swapping images

static void	enemy_movements(t_program *g)
{
	int		i;
	t_enemy	x1;

	i = -1;
	while (++i < g->map.enemy)
	{
		x1 = g->x1[i];
		if (g->lines[x1.now.y - 1][x1.now.x] == '0')
			g->lines[x1.now.y - 1][x1.now.x] = 'V';
		else if (g->lines[x1.now.y + 1][x1.now.x] == '0')
			g->lines[x1.now.y + 1][x1.now.x] = 'V';
		else
			continue ;
		g->lines[x1.now.y][x1.now.x] = '0';
	}
}

//very simple movement along the y axis to imitate the movement of up and down by swapping positions with the empty tiles in the map.