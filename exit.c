/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obibby <obibby@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 15:27:02 by obibby            #+#    #+#             */
/*   Updated: 2022/04/26 13:41:20 by obibby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	restart_game(t_game *g)
{
	int	x;
	int	y;

	y = 0;
	while (g->map[y])
	{
		x = -1;
		while (g->map[y][++x])
			g->map[y][x] = g->omap[y][x];
		y++;
	}
	g->playerbb = g->player1bb;
	g->playerwb = g->player1wb;
	free_images(g);
	free_entity(g);
	g->movecount = 0;
	g->victory = 0;
	g->defeat = 0;
	g->ccount = 0;
	g->entity = init_entity(g, 1, 0, 0);
	assign_images(g, 34);
	g->wscreen = create_img(g, colourshift(0, 255, 255, 255));
}

void	free_eimages(t_game *g)
{
	int	i;

	i = 1;
	while (g->entity[i])
	{
		if (g->entity[i]->id != EXIT && g->entity[i]->id != COLLECT)
		{
			mlx_destroy_image(g->mlx, g->entity[i]->imgb);
			mlx_destroy_image(g->mlx, g->entity[i]->imgw);
			mlx_destroy_image(g->mlx, g->entity[i]->imge);
			mlx_destroy_image(g->mlx, g->entity[i]->imgcb);
			mlx_destroy_image(g->mlx, g->entity[i]->imgcw);
		}
		i++;
	}
}

void	free_images(t_game *g)
{
	mlx_destroy_image(g->mlx, g->exit);
	mlx_destroy_image(g->mlx, g->collectbb);
	mlx_destroy_image(g->mlx, g->collectwb);
	mlx_destroy_image(g->mlx, g->eplayer);
	mlx_destroy_image(g->mlx, g->floor_b);
	mlx_destroy_image(g->mlx, g->floor_w);
	mlx_destroy_image(g->mlx, g->player1bb);
	mlx_destroy_image(g->mlx, g->player1wb);
	mlx_destroy_image(g->mlx, g->player2bb);
	mlx_destroy_image(g->mlx, g->player2wb);
	mlx_destroy_image(g->mlx, g->wall_img);
	mlx_destroy_image(g->mlx, g->wscreen->ptr);
	free_eimages(g);
	free(g->wscreen);
}

int	free_entity(t_game *g)
{
	int	i;

	i = 1;
	if (g->entity[0])
		free(g->entity[0]);
	while (g->entity[i])
		free(g->entity[i++]);
	free(g->entity);
	if (g->defeat == 1)
		free(g->killer);
	return (1);
}

int	ft_exit(t_game *g, int code)
{
	if (code > 3)
	{
		mlx_destroy_window(g->mlx, g->window);
		free(g->maps);
	}
	if (code > 2)
	{
		free_images(g);
		free_entity(g);
		free_map(g->map, NULL);
		free_map(g->omap, NULL);
	}
	if (code > 1)
	{
		mlx_destroy_display(g->mlx);
		free(g->mlx);
	}
	exit (0);
}
