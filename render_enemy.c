/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_enemy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obibby <obibby@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 23:39:48 by obibby            #+#    #+#             */
/*   Updated: 2022/04/26 13:37:59 by obibby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	rwt_enemy(t_game *g, int x, int y, int i)
{
	if (g->omap[y][x] == 'C' && g->ccount == 0)
		mlx_put_image_to_window(g->mlx, g->window,
			g->entity[i]->imgcw, (x * 34) + 1, (y * 34) + 1);
	else if (g->omap[y][x] == 'E')
		mlx_put_image_to_window(g->mlx, g->window,
			g->entity[i]->imge, (x * 34) + 1, (y * 34) + 1);
	else
		mlx_put_image_to_window(g->mlx, g->window,
			g->entity[i]->imgw, (x * 34) + 1, (y * 34) + 1);
}

void	rbt_enemy(t_game *g, int x, int y, int i)
{
	if (g->omap[y][x] == 'C' && g->ccount == 0)
		mlx_put_image_to_window(g->mlx, g->window,
			g->entity[i]->imgcb, (x * 34) + 1, (y * 34) + 1);
	else if (g->omap[y][x] == 'E')
		mlx_put_image_to_window(g->mlx, g->window,
			g->entity[i]->imge, (x * 34) + 1, (y * 34) + 1);
	else
		mlx_put_image_to_window(g->mlx, g->window,
			g->entity[i]->imgb, (x * 34) + 1, (y * 34) + 1);
}

void	render_enemy(t_game *g, int x, int y, int col)
{
	int	i;

	i = 1;
	while (g->entity[i])
	{
		if (g->entity[i]->id == COLLECT || g->entity[i]->id == EXIT)
		{
			i++;
			continue ;
		}
		if (g->entity[i]->xcoord == x && g->entity[i]->ycoord == y)
		{
			if (col == 0)
				rbt_enemy(g, x, y, i);
			else
				rwt_enemy(g, x, y, i);
		}
		i++;
	}
}
