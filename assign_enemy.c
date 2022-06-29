/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign_enemy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obibby <obibby@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 00:08:47 by obibby            #+#    #+#             */
/*   Updated: 2022/04/26 00:34:44 by obibby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	assign_queen(t_game *g, int i, int s)
{
	g->entity[i]->imgb = mlx_xpm_file_to_image(g->mlx,
			"sprites/queenbb.xpm", &s, &s);
	g->entity[i]->imgw = mlx_xpm_file_to_image(g->mlx,
			"sprites/queenwb.xpm", &s, &s);
	g->entity[i]->imge = mlx_xpm_file_to_image(g->mlx,
			"sprites/equeen.xpm", &s, &s);
	g->entity[i]->imgcb = mlx_xpm_file_to_image(g->mlx,
			"sprites/cqueenb.xpm", &s, &s);
	g->entity[i]->imgcw = mlx_xpm_file_to_image(g->mlx,
			"sprites/cqueenw.xpm", &s, &s);
}

void	assign_pawn(t_game *g, int i, int s)
{
	g->entity[i]->imgb = mlx_xpm_file_to_image(g->mlx,
			"sprites/pawnbb.xpm", &s, &s);
	g->entity[i]->imgw = mlx_xpm_file_to_image(g->mlx,
			"sprites/pawnwb.xpm", &s, &s);
	g->entity[i]->imge = mlx_xpm_file_to_image(g->mlx,
			"sprites/epawn.xpm", &s, &s);
	g->entity[i]->imgcb = mlx_xpm_file_to_image(g->mlx,
			"sprites/cpawnb.xpm", &s, &s);
	g->entity[i]->imgcw = mlx_xpm_file_to_image(g->mlx,
			"sprites/cpawnw.xpm", &s, &s);
}

void	assign_knight(t_game *g, int i, int s)
{
	g->entity[i]->imgb = mlx_xpm_file_to_image(g->mlx,
			"sprites/knightbb.xpm", &s, &s);
	g->entity[i]->imgw = mlx_xpm_file_to_image(g->mlx,
			"sprites/knightwb.xpm", &s, &s);
	g->entity[i]->imge = mlx_xpm_file_to_image(g->mlx,
			"sprites/eknight.xpm", &s, &s);
	g->entity[i]->imgcb = mlx_xpm_file_to_image(g->mlx,
			"sprites/cknightb.xpm", &s, &s);
	g->entity[i]->imgcw = mlx_xpm_file_to_image(g->mlx,
			"sprites/cknightw.xpm", &s, &s);
}
