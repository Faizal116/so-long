#include "so_long.h"

void	player_x_coins(t_program *g)
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

void	enemy_movements(t_program *g)
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

int	ft_idle_anim(void *param)
{
	t_program 	*g;
	static int	frames;

	g = (t_program *)param;
	frames++;
	if (frames == ANIM_FRAMES)
		g->player1.now.y += 1;
	else if (frames >= ANIM_FRAMES * 2)
	{
		g->player1.now.y -= 1;
		frames = 0;
	}
	mlx_clear_window(g->mlx, g->window);
	xpm_to_window(g);
	return (0);
}

//trying out idle animations, would need more tweaking.