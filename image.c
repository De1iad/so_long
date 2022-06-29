/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obibby <obibby@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 23:08:10 by obibby            #+#    #+#             */
/*   Updated: 2022/04/26 00:07:04 by obibby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_entity	*killer_init(t_game *g, t_entity *e)
{
	t_entity	*killer;

	killer = ft_calloc(1, sizeof(t_entity));
	killer->id = e->id;
	killer->name = e->name;
	killer->xcoord = e->xcoord;
	killer->ycoord = e->ycoord;
	g->defeat = 1;
	return (killer);
}

void	enemy_type(t_entity *e, t_game *g, int x, int y)
{
	if (e->id == QUEEN)
		queen_move(e, g, x, y);
	if (e->id == PAWN)
		pawn_move(e, g, x, y);
	if (e->id == KNIGHT)
		knight_move(e, g, x, y);
}

int	colourshift(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

void	*create_img(t_game *g, int colour)
{
	t_screen	*img;
	int			x;
	int			y;

	img = malloc(sizeof(t_screen));
	img->ptr = mlx_new_image(g->mlx, g->max_x * 34, g->max_y * 34);
	img->addr = mlx_get_data_addr(img->ptr, &img->bpp,
			&img->sline, &img->endian);
	y = 0;
	while (y < g->max_y * 34)
	{
		x = 0;
		while (x < g->max_x * 34)
		{
			img->addr[x * 4 + img->sline * y] = colour;
			img->addr[(x * 4 + img->sline * y) + 1] = colour >> 8;
			img->addr[(x * 4 + img->sline * y) + 2] = colour >> 16;
			x++;
		}
		y += 1;
	}
	return (img);
}
