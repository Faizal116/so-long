# include "so_long.h"

void	read_line(int fd, char *buffer, char **map)
{
	int		i;
	char	*temp;

	if (!*map || !ft_strchr(*map, '\n'))
	{
		i = read(fd, buffer, BUFFER_SIZE);
		while (i > 0)
		{
			buffer[i] = 0;
			if (!*map)
				*map = ft_strdup(buffer);
			else
			{
				temp = *map;
				*map = ft_strjoin(*map, buffer);
				free(temp);
			}
			if (ft_strchr(buffer, '\n'))
				break ;
			i = read(fd, buffer, BUFFER_SIZE);
		}
	}
	free(buffer);
}

static char	*split_read_part(int fd, char **map)
{
	int		i;
	int		j;
	char	*splitted;
	char	*temp;

	if (!*map)
	{
		close(fd);
		return (0);
	}
	if (!ft_strchr(*map, '\n'))
	{
		splitted = ft_strdup(*map);
		free(*map);
		*map = 0;
		return (splitted);
	}
	i = ft_strlen(*map);
	j = ft_strlen(ft_strchr(*map, '\n'));
	splitted = ft_substr(*map, 0, i - j);
	temp = *map;
	*map = ft_substr(ft_strchr(*map, '\n'), 1, j - 1);
	free(temp);
	return (splitted);
}

char	*special_get_next_line(int fd)
{
	char		*buffer;
	static char	*str;
	static char	*rest_of_file;
	
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (0);
	if (fd == -1 || read(fd, buffer, 0) == -1)
	{
		free(buffer);
		close(fd);
		return (0);
	}
	read_line(fd, buffer, &str);
	rest_of_file = split_read_part(fd, &str);
	return (rest_of_file);
}