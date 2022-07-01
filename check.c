/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obibby <obibby@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 13:57:13 by obibby            #+#    #+#             */
/*   Updated: 2022/07/01 21:29:49 by obibby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	max_coords(t_game *g)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (g->map[y])
	{
		g->max_y = y;
		y++;
	}
	y = 0;
	while (g->map[y][x + 1])
	{
		g->max_x = x;
		x++;
	}
}

int	check_unknown(t_game *g)
{
	int	x;
	int	y;
	int	pcount;

	x = 0;
	y = 0;
	pcount = 0;
	while (g->map[y])
	{
		while (g->map[y][x])
		{
			if (g->map[y][x] != FLOOR && g->map[y][x] != WALL
				&& g->map[y][x] != PLAYER && g->map[y][x] != EXIT
				&& g->map[y][x] != COLLECT && g->map[y][x] != '\n')
				return (error_write("Unknown character in map."));
			else if (g->map[y][x] == PLAYER)
				pcount++;
			x++;
		}
		x = 0;
		y++;
	}
	if (pcount > 1)
		return (error_write("Too many player starts in map."));
	return (0);
}

int	check_entities(t_game *g)
{
	int	i;
	int	collect;
	int	exit;

	i = 1;
	collect = 0;
	exit = 0;
	if (!g->entity[0])
		return (error_write("No player found in map!"));
	while (g->entity[i])
	{
		if (g->entity[i]->id == COLLECT)
			collect += 1;
		if (g->entity[i]->id == EXIT)
			exit += 1;
		i++;
	}
	if (exit == 0 || collect == 0)
		return (error_write("Wrong number of tokens or exits!"));
	return (0);
}

int	check_map(t_game *g)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (g->map[g->max_y][x] && x <= g->max_x)
	{
		if (g->map[g->max_y][x] != WALL || g->map[0][x] != WALL)
			return (error_write("Map not enclosed by walls or wrong shape."));
		x++;
	}
	while (g->map[y] && y <= g->max_y)
	{
		if (g->map[y][g->max_x] != WALL || g->map[y][0] != WALL)
			return (error_write("Map not enclosed by walls or wrong shape."));
		y++;
	}
	if (check_unknown(g) == 1)
		return (1);
	return (check_entities(g));
}
