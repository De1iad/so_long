/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obibby <obibby@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 19:45:09 by obibby            #+#    #+#             */
/*   Updated: 2022/04/25 21:51:01 by obibby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	move_distance(int *sign, t_game *g)
{
	int	movedist;

	movedist = (randno(g));
	*sign = 1;
	if (movedist < 0)
	{
		movedist = -movedist;
		*sign = -1;
	}
	return (movedist);
}

void	rand_smove(t_entity *e, t_game *g, int x, int y)
{
	int	movedist;
	int	n;
	int	sign;

	movedist = move_distance(&sign, g);
	n = 0;
	if (randno(g) % 2 != 0)
	{
		while (n++ != movedist % y
			&& g->map[e->ycoord + sign][e->xcoord] != WALL
			&& g->map[e->ycoord + sign][e->xcoord] < 'Q'
			&& (g->map[e->ycoord + sign][e->xcoord] != 'P' || e->id != 'R'))
			e->ycoord += sign;
	}
	else
	{
		while (n++ != movedist % x
			&& g->map[e->ycoord][e->xcoord + sign] != WALL
			&& g->map[e->ycoord][e->xcoord + sign] < 'Q'
			&& (g->map[e->ycoord][e->xcoord + sign] != 'P' || e->id != 'R'))
			e->xcoord += sign;
	}
}

void	rand_knight(t_entity *e, t_game *g, int x, int y)
{
	int	sign;

	sign = 1;
	if (randno(g) < 0)
		sign = -sign;
	if (x == 0)
		x = sign;
	if (y == 0)
		y = sign;
	if ((randno(g) % 2) != 0 && e->ycoord + 2 * y > 0 && e->xcoord + 1 * x > 0
		&& g->max_y > e->ycoord + 2 * y && g->max_x > e->xcoord + 1 * x
		&& g->map[e->ycoord + 2 * y][e->xcoord + 1 * x] != WALL
		&& g->map[e->ycoord + 2 * y][e->xcoord + 1 * x] < 'Q')
	{
		e->ycoord += 2 * y;
		e->xcoord += 1 * x;
	}
	else if (e->ycoord + 1 * y > 0 && e->xcoord + 2 * x > 0
		&& g->max_y > e->ycoord + 1 * y && g->max_x > e->xcoord + 2 * x
		&& g->map[e->ycoord + 1 * y][e->xcoord + 2 * x] != WALL
		&& g->map[e->ycoord + 1 * y][e->xcoord + 2 * x] < 'Q')
	{
		e->ycoord += 1 * y;
		e->xcoord += 2 * x;
	}
}

void	straight_move(t_entity *e, t_game *g, int x, int y)
{
	if (x == 0)
	{
		while (g->entity[0]->ycoord != e->ycoord
			&& g->map[e->ycoord + y][e->xcoord] != WALL)
			e->ycoord += y;
	}
	else if (y == 0)
	{
		while (g->entity[0]->xcoord != e->xcoord
			&& g->map[e->ycoord][e->xcoord + x] != WALL)
			e->xcoord += x;
	}
}

void	diagonal_move(t_entity *e, t_game *g, int x, int y)
{
	while (g->entity[0]->ycoord != e->ycoord
		&& g->entity[0]->xcoord != e->xcoord
		&& g->map[e->ycoord + y][e->xcoord + x] != WALL)
	{
		e->ycoord += y;
		e->xcoord += x;
	}
}
