/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obibby <obibby@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 16:32:30 by obibby            #+#    #+#             */
/*   Updated: 2022/04/25 20:11:32 by obibby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**free_map(char **map, char *str)
{
	int	i;

	i = 0;
	if (str)
		free(str);
	if (map)
	{
		while (map[i])
			free (map[i++]);
		free (map);
	}
	return (NULL);
}

char	**store_map(int fd, int lines)
{
	char	*str;
	char	**map;
	int		y;
	int		x;

	y = 0;
	x = -1;
	str = get_next_line(fd);
	map = ft_calloc(lines + 1, sizeof(char *));
	if (!map)
		return (free_map(map, str));
	while (str)
	{
		map[y] = ft_calloc(ft_strlen(str) + 1, sizeof(char));
		if (!map[y])
			return (free_map(map, str));
		while (str[++x])
			map[y][x] = str[x];
		free(str);
		str = get_next_line(fd);
		x = -1;
		y++;
	}
	return (map);
}

int	map_validity(int argc, char **argv)
{
	int	i;

	if (argc == 1)
		return (error_write("No map found."));
	if (argc > 2)
		return (error_write("Too many arguments."));
	i = ft_strlen(argv[1]);
	if (argv[1][i - 1] != 'r' || argv[1][i - 2] != 'e' ||
			argv[1][i - 3] != 'b' || argv[1][i - 4] != '.')
		return (error_write("Not a valid map type."));
	return (0);
}

int	createmap(t_game *g, int argc, char **argv, int lines)
{
	int		fd;
	char	*ptr;

	if (map_validity(argc, argv) == 1)
		return (1);
	fd = open(argv[1], O_RDWR);
	ptr = get_next_line(fd);
	if (!ptr)
		return (error_write("Map file doesn't exist."));
	while (ptr)
	{
		lines++;
		free(ptr);
		ptr = get_next_line(fd);
	}
	close(fd);
	fd = open(argv[1], O_RDWR);
	g->map = store_map(fd, lines);
	close(fd);
	fd = open(argv[1], O_RDWR);
	g->omap = store_map(fd, lines);
	close(fd);
	if (!g->map || !g->omap)
		return (error_write("Malloc fail."));
	return (0);
}
