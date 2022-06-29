/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obibby <obibby@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 21:21:33 by obibby            #+#    #+#             */
/*   Updated: 2022/04/26 13:40:17 by obibby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	assign_eimages(t_game *g, int s)
{
	int	i;

	i = 1;
	while (g->entity[i])
	{
		if (g->entity[i]->id == QUEEN)
			assign_queen(g, i, s);
		if (g->entity[i]->id == PAWN)
			assign_pawn(g, i, s);
		if (g->entity[i]->id == KNIGHT)
			assign_knight(g, i, s);
		i++;
	}	
}

void	assign_images(t_game *g, int s)
{
	g->floor_w = mlx_xpm_file_to_image(g->mlx, "sprites/whiteb.xpm", &s, &s);
	g->floor_b = mlx_xpm_file_to_image(g->mlx, "sprites/blackb.xpm", &s, &s);
	g->collectwb = mlx_xpm_file_to_image(g->mlx, "sprites/collectwb.xpm",
			&s, &s);
	g->collectbb = mlx_xpm_file_to_image(g->mlx, "sprites/collectbb.xpm",
			&s, &s);
	g->exit = mlx_xpm_file_to_image(g->mlx, "sprites/exit.xpm", &s, &s);
	g->wall_img = mlx_xpm_file_to_image(g->mlx, "sprites/border.xpm", &s, &s);
	g->player1wb = mlx_xpm_file_to_image(g->mlx, "sprites/playerwb.xpm",
			&s, &s);
	g->player1bb = mlx_xpm_file_to_image(g->mlx, "sprites/playerbb.xpm",
			&s, &s);
	g->player2wb = mlx_xpm_file_to_image(g->mlx, "sprites/player2wb.xpm",
			&s, &s);
	g->player2bb = mlx_xpm_file_to_image(g->mlx, "sprites/player2bb.xpm",
			&s, &s);
	g->eplayer = mlx_xpm_file_to_image(g->mlx, "sprites/eplayer.xpm",
			&s, &s);
	assign_eimages(g, s);
	g->playerbb = g->player1bb;
	g->playerwb = g->player1wb;
}

t_entity	*init_other(int x, int y, t_game *g)
{
	t_entity	*e;

	e = ft_calloc(1, sizeof(t_entity));
	if (!e)
		return (NULL);
	e->id = g->map[y][x];
	if (e->id == 'Q')
		e->name = "queen";
	if (e->id == 'R')
		e->name = "pawn";
	if (e->id == 'S')
		e->name = "knight";
	e->xcoord = x;
	e->ycoord = y;
	return (e);
}

t_entity	*init_player(int x, int y)
{
	t_entity	*e;

	e = ft_calloc(1, sizeof(t_entity));
	if (!e)
		return (NULL);
	e->id = 'P';
	e->name = "player";
	e->xcoord = x;
	e->ycoord = y;
	return (e);
}

t_entity	**init_entity(t_game *g, int i, int x, int y)
{
	t_entity	**e;

	e = ft_calloc(20, sizeof(t_entity));
	if (!e)
		return (NULL);
	while (g->map[y])
	{
		while (g->map[y][x])
		{
			if (g->map[y][x] == 'P')
				e[0] = init_player(x, y);
			else if ((g->map[y][x] >= 'Q' && g->map[y][x] <= 'S')
				|| g->map[y][x] == 'E' || g->map[y][x] == 'C')
			{
				e[i] = init_other(x, y, g);
				i++;
			}
			x++;
		}
		x = 0;
		y++;
	}
	return (e);
}
