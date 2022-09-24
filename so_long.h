#ifndef SO_LONG_H

# define SO_LONG_H

# define ESC 53
# define LEFT 0
# define DOWN 1
# define RIGHT 2
# define UP 13
# define BUFFER_SIZE 100

# include <stdlib.h>
# include <stdio.h>
# include "libft/libft.h"
# include <fcntl.h>

typedef struct s_coord
{
	int	x;
	int	y;
}	t_coord;

typedef struct s_player
{
	int		c;
	int		movecount;
	t_coord	now;
	t_coord	to;
}	t_player;

typedef struct s_enemy
{
	t_coord now;
}	t_enemy;

typedef struct s_map
{
	int		row;
	int		col;
	int		coins;
	int		exit;
	int		player;
	int		enemy;
	int		diff_col;
	int		px;
	char	**lines;
}	t_map;

typedef struct s_program
{
	char		**lines;
	void		*empty;
	void		*coins;
	void		*coins2;
	void		*exit;
	void		*p;
	void		*p1;
	void		*p2;
	void		*enemy;
	void		*mlx;
	void		*window;
	t_player	player1;
	t_enemy		*x1;
	t_map		map;
}	t_program;

char	*get_next_line(int fd);
int	check_map(char *file, t_map *map);
void	init_game(t_program *g);
void	link_xpm(char *file, t_program *g);
void	alloc_enemies(t_program *g);
void	xpm_to_window(t_program  *g);
static int	press_x(t_program *g);
void	game_over(t_program *g);

static void	player_x_coins(t_program *g);
static void	enemy_movements(t_program *g);

void	movement(t_program *g);
static int	key_binding(int pressed, t_program *g);

#endif