#include "so_long.h"

void	init_game(t_program *g)
{
	g->player1.c = 0;
	g->player1.movecount = 0;
	g->map.coins = 0;
	g->map.exit = 0;
	g->map.player = 0;
	g->map.enemy = 0;
	g->map.diff_col = 0;
	g->map.px = 32;
}