#include "so_long.h"

static int	count_items(char *line, int c)
{
	int	count;

	count = 0;
	while (*line)
		if (*line++ == c)
			++count;
		return (count);
}

static int	check_ber(char *file)
{
	const	char	*extension;
	const	char	*length;

	extension = ft_strrchr(file, '.');
	length = ft_strlen(extension);
	if (!ft_strncmp(extension, ".ber", length))
		return (1);
	return (0);
}

static int	check_border(char *line, char *border)
{
	int			i;
	char		*temp;
	int			length;

	i = 0;
	length = ft_strlen(line);
	while (*line)
	{
		temp = border;
		while (*temp)
			if (*line == *temp++)
				i++;
			++line;
	}
	if (i != length)
		return (0);
	return (1);
}

int	check_cep(char *file, t_map *map)
{
	int		i;
	int		fd;
	char	*line;

	i = 0;
	fd = open(file, O_RDONLY);
	line = get_next_line(fd);
	while (line && ++i)
	{
		if (i == 1)
			map->col = ft_strlen(line);
		else if (ft_strlen(line) != map->col)
			map->diff_col = 1;
		map->coins += count_items(line, 'C');
		map->exit += count_items(line, 'E');
		map->player += count_items(line, 'P');
		map->enemy += count_items(line, 'V');
		free(line);
		line = get_next_line(fd);
	}
	map->row = i;
	if (!map->coins || map->exit != 1 || map->player != 1 || map->diff_col)
		return (0);
	return (1);
}

int	check_map(char *file, t_map *map)
{
	int			i;
	int			ok;
	char		*line;
	int	fd;

	ok = 1; //means its fine if 1
	fd = open(file, O_RDONLY);
	while (line && ++i)
	{
		if (!check_ber(file) || !check_cep(file, map))
			ok = 0;
		else if (i != 1 && i != map->row && (!check_border(line, "01CEPV") \
				|| line[0] != '1' || line[map->col - 1] != '1'))
			ok = 0;
		free(line);
		line = get_next_line(fd);
	}
	if (!ok)
		return (0);
	return (1);
}

