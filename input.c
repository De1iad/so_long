/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obibby <obibby@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 22:26:16 by obibby            #+#    #+#             */
/*   Updated: 2022/04/25 20:26:54 by obibby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

void	relative_loc(t_entity *e, t_game *g, int *x, int *y)
{
	*x = 0;
	*y = 0;
	if (g->entity[0]->xcoord < e->xcoord)
		*x -= 1;
	if (g->entity[0]->xcoord > e->xcoord)
		*x += 1;
	if (g->entity[0]->ycoord < e->ycoord)
		*y -= 1;
	if (g->entity[0]->ycoord > e->ycoord)
		*y += 1;
}

void	ft_path(t_game *g, t_entity *p, int x, int y)
{
	if (g->map[p->ycoord][p->xcoord] == PLAYER)
		g->map[p->ycoord][p->xcoord] = FLOOR;
	else
		g->map[p->ycoord][p->xcoord] = g->omap[p->ycoord][p->xcoord];
	p->xcoord = p->xcoord + x;
	p->ycoord = p->ycoord + y;
	if (g->map[p->ycoord][p->xcoord] == COLLECT)
	{
		g->playerbb = g->player2bb;
		g->playerwb = g->player2wb;
		g->map[p->ycoord][p->xcoord] = PLAYER;
		g->ccount = 1;
	}
	else if (g->map[p->ycoord][p->xcoord] == EXIT)
	{
		if (g->playerbb == g->player2bb)
			g->victory = 1;
		g->map[p->ycoord][p->xcoord] = EPLAYER;
	}
	else
		g->map[p->ycoord][p->xcoord] = PLAYER;
	return ;
}

void	enemy_move(t_game *g)
{
	t_entity	*e;
	int			x;
	int			y;
	int			i;

	i = 1;
	while (g->entity[i])
	{
		e = g->entity[i++];
		g->randseedx *= g->randseedy + e->xcoord * e->ycoord;
		if (e->id == EXIT || e->id == COLLECT)
			continue ;
		if (g->omap[e->ycoord][e->xcoord] == 'E'
			|| (g->omap[e->ycoord][e->xcoord] == 'C' && g->ccount == 0))
			g->map[e->ycoord][e->xcoord] = g->omap[e->ycoord][e->xcoord];
		else
			g->map[e->ycoord][e->xcoord] = FLOOR;
		relative_loc(e, g, &x, &y);
		enemy_type(e, g, x, y);
		if (e->xcoord == g->entity[0]->xcoord
			&& e->ycoord == g->entity[0]->ycoord)
			g->killer = killer_init(g, e);
	}
}

int	ft_move(int key, t_game *g)
{
	t_entity	*p;
	int			x;
	int			y;

	p = g->entity[0];
	x = 0;
	y = 0;
	if (key == 119 && g->map[p->ycoord - 1][p->xcoord] != WALL
		&& g->map[p->ycoord - 1][p->xcoord] < 'Q')
		y = -1;
	if (key == 97 && g->map[p->ycoord][p->xcoord - 1] != WALL
		&& g->map[p->ycoord][p->xcoord - 1] < 'Q')
		x = -1;
	if (key == 115 && g->map[p->ycoord + 1][p->xcoord] != WALL
		&& g->map[p->ycoord + 1][p->xcoord] < 'Q')
		y = 1;
	if (key == 100 && g->map[p->ycoord][p->xcoord + 1] != WALL
		&& g->map[p->ycoord][p->xcoord + 1] < 'Q')
		x = 1;
	g->randseedx = x;
	g->randseedy = y;
	if (x + y == 0)
		return (0);
	ft_path(g, p, x, y);
	return (0);
}

int	input(int key, t_game *g)
{
	if (key == 65307)
		ft_exit(g, 4);
	if ((key == 119 || key == 97 || key == 115 || key == 100)
		&& g->victory + g->defeat == 0)
	{
		ft_move(key, g);
		g->movecount += 1;
		if (g->victory != 1)
			enemy_move(g);
	}
	if (key == 114)
		restart_game(g);
	if (key == 110)
		next_level(g);
	if (g->victory == 0 && g->defeat == 0)
		render_frame(g);
	else
		render_vicdef(g);
	return (0);
}
