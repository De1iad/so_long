/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obibby <obibby@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 19:25:42 by obibby            #+#    #+#             */
/*   Updated: 2022/04/25 21:38:03 by obibby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	queen_move(t_entity *e, t_game *g, int x, int y)
{
	int	dif_y;
	int	dif_x;

	dif_y = (g->entity[0]->ycoord - e->ycoord);
	dif_x = (g->entity[0]->xcoord - e->xcoord);
	if (x == 0 || y == 0)
		straight_move(e, g, x, y);
	else if (dif_y == dif_x || dif_y + dif_x == 0)
		diagonal_move(e, g, x, y);
	else
		rand_smove(e, g, g->max_x, g->max_y);
	g->map[e->ycoord][e->xcoord] = QUEEN;
}

void	pawn_move(t_entity *e, t_game *g, int x, int y)
{
	int	dif_y;
	int	dif_x;

	dif_y = g->entity[0]->ycoord - e->ycoord;
	dif_x = g->entity[0]->xcoord - e->xcoord;
	if (dif_y < 0)
		dif_y = -dif_y;
	if (dif_x < 0)
		dif_x = -dif_x;
	if (dif_y == 1 && dif_x == 1)
	{
		e->xcoord += x;
		e->ycoord += y;
	}
	else
		rand_smove(e, g, 2, 2);
	g->map[e->ycoord][e->xcoord] = PAWN;
}

void	knight_move(t_entity *e, t_game *g, int x, int y)
{
	int	dif_y;
	int	dif_x;

	dif_y = g->entity[0]->ycoord - e->ycoord;
	dif_x = g->entity[0]->xcoord - e->xcoord;
	if (x != 0 && y != 0 && dif_y == 2 * y && dif_x == 1 * x
		&& g->map[e->ycoord + 2 * y][e->xcoord + 1 * x] != WALL
		&& g->map[e->ycoord + 2 * y][e->xcoord + 1 * x] < 'Q')
	{
		e->ycoord += 2 * y;
		e->xcoord += 1 * x;
	}
	else if (x != 0 && y != 0 && dif_y == 1 * y && dif_x == 2 * x
		&& g->map[e->ycoord + 1 * y][e->xcoord + 2 * x] != WALL
		&& g->map[e->ycoord + 1 * y][e->xcoord + 2 * x] < 'Q')
	{
		e->ycoord += 1 * y;
		e->xcoord += 2 * x;
	}
	else
		rand_knight(e, g, x, y);
	g->map[e->ycoord][e->xcoord] = KNIGHT;
}

int	randno(t_game *g)
{
	static int	rand_no;

	rand_no = (rand_no * 1103515245 + 12345 + g->randseedx);
	return ((rand_no / 65536) % 32768);
}
