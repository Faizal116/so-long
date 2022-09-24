#include "so_long.h"

static int	p_or_v_pos(t_program *g, int i, int j, int k)
{
	if (k >= 0)
	{
		g->x1[k].now.x = j;
		g->x1[k].now.y = i;
	}
	else
	{
		g->player1.now.x = j;
		g->player1.now.y = i;
		g->player1.to.x = j;
		g->player1.to.y = i;
	}
	return (1);
}

void	link_xpm(char *file, t_program *g)
{
	int		i;
	char	*line;
	char	**res;
	int		fd;

	fd = open(file, O_RDONLY);
	res = malloc((g->map.row + 1) * sizeof(char *));
	if (!res)
		return ;
	i = 0;
	line = get_next_line(fd);
	while (line)
	{
		res[i++] = line;
		line = get_next_line(fd);
	}
	res[i] = 0;
	g->lines = res;
	g->empty = mlx_xpm_file_to_image(g->mlx, "images/walls.xpm", &g->map.px, &g->map.px);
	g->coins = mlx_xpm_file_to_image(g->mlx, "images/c1.xpm", &g->map.px, &g->map.px);
	g->coins2 = mlx_xpm_file_to_image(g->mlx, "images/c2.xpm", &g->map.px, &g->map.px);
	g->exit =  mlx_xpm_file_to_image(g->mlx, "images/exit.xpm", &g->map.px, &g->map.px);
	g->enemy = mlx_xpm_file_to_image(g->mlx, "images/enemy.xpm", &g->map.px, &g->map.px);
	g->p1 = mlx_xpm_file_to_image(g->mlx, "images/p1.xpm", &g->map.px, &g->map.px);
	g->p2 = mlx_xpm_file_to_image(g->mlx, "images/p2.xpm", &g->map.px, &g->map.px);
	g->p = g->p2;
}

void	alloc_enemies(t_program *g)
{
	t_enemy *x1;

	x1 = malloc(g->map.enemy * sizeof(t_enemy));
	if (!x1)
		return ;
	g->x1 = x1;
}

void	xpm_to_window(t_program  *g)
{
	int	a;
	int	b;
	int	c;
	int	(*f)(void *, void *, void *, int x, int y);

	f = mlx_put_image_to_window;
	a = -1;
	c = -1;
	while (++a < g->map.row)
	{
		b = -1;
		while (++b < g->map.col)
		{
			if (g->lines[a][b] == '1')
				f(g->mlx, g->window, g->empty, b * g->map.px, a * g->map.px);
			else if (g->lines[a][b] == 'P' && p_or_v_pos(g, a, b, -1))
				f(g->mlx, g->window, g->p, b * g->map.px, a * g->map.px);
			else if (g->lines[a][b] == 'C')
				f(g->mlx, g->window, g->coins, b * g->map.px, a * g->map.px);
			else if (g->lines[a][b] == 'E')
				f(g->mlx, g->window, g->exit, b * g->map.px, a * g->map.px);
			else if (g->lines[a][b] == 'V' && p_or_v_pos(g, a, b, ++c))
				f(g->mlx, g->window, g->enemy, b * g->map.px, a * g->map.px);
		}
	}
}