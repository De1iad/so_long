/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obibby <obibby@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 09:23:38 by obibby            #+#    #+#             */
/*   Updated: 2022/08/01 19:39:49 by obibby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_image(t_game *g, int x, int y)
{
	int	fcount;

	fcount = -1;
	while (g->map[y])
	{
		while (g->map[y][x])
		{
			if (g->map[y][x] == WALL)
				mlx_put_image_to_window(g->mlx, g->window,
					g->wall_img, (x * 34) + 1, (y * 34) + 1);
			else if (fcount == 1)
				render_black(g, x, y);
			else
				render_white(g, x, y);
			x++;
			fcount *= -1;
		}
		y++;
		if (x % 2 == 0)
			fcount *= -1;
		x = 0;
	}
}

void	render_vicdef(t_game *g)
{
	int		x;
	int		y;
	char	*moves;

	x = g->max_x * 34 / 2;
	y = g->max_y * 34 / 2;
	mlx_clear_window(g->mlx, g->window);
	moves = ft_itoa(g->movecount);
	if (g->victory == 1)
		render_victory(g, moves, x, y);
	else
		render_defeat(g, moves, x, y);
	free(moves);
}

void	render_black(t_game *g, int x, int y)
{
	if (g->map[y][x] == FLOOR)
		mlx_put_image_to_window(g->mlx, g->window,
			g->floor_b, (x * 34) + 1, (y * 34) + 1);
	else if (g->map[y][x] == COLLECT)
		mlx_put_image_to_window(g->mlx, g->window,
			g->collectbb, (x * 34) + 1, (y * 34) + 1);
	else if (g->map[y][x] == EXIT)
		mlx_put_image_to_window(g->mlx, g->window,
			g->exit, (x * 34) + 1, (y * 34) + 1);
	else if (g->map[y][x] == PLAYER)
		mlx_put_image_to_window(g->mlx, g->window,
			g->playerbb, (x * 34) + 1, (y * 34) + 1);
	else if (g->map[y][x] == EPLAYER)
		mlx_put_image_to_window(g->mlx, g->window,
			g->eplayer, (x * 34) + 1, (y * 34) + 1);
	else if (g->map[y][x] >= QUEEN && g->map[y][x] <= KNIGHT)
		render_enemy(g, x, y, 0);
}

void	render_white(t_game *g, int x, int y)
{
	if (g->map[y][x] == FLOOR)
		mlx_put_image_to_window(g->mlx, g->window,
			g->floor_w, (x * 34) + 1, (y * 34) + 1);
	else if (g->map[y][x] == COLLECT)
		mlx_put_image_to_window(g->mlx, g->window,
			g->collectwb, (x * 34) + 1, (y * 34) + 1);
	else if (g->map[y][x] == EXIT)
		mlx_put_image_to_window(g->mlx, g->window,
			g->exit, (x * 34) + 1, (y * 34) + 1);
	else if (g->map[y][x] == PLAYER)
		mlx_put_image_to_window(g->mlx, g->window,
			g->playerwb, (x * 34) + 1, (y * 34) + 1);
	else if (g->map[y][x] == EPLAYER)
		mlx_put_image_to_window(g->mlx, g->window,
			g->eplayer, (x * 34) + 1, (y * 34) + 1);
	else if (g->map[y][x] >= QUEEN && g->map[y][x] <= KNIGHT)
		render_enemy(g, x, y, 1);
}

int	render_frame(t_game *g)
{
	int			x;
	int			y;
	char		*moves;

	x = 0;
	y = 0;
	mlx_clear_window(g->mlx, g->window);
	put_image(g, x, y);
	moves = ft_itoa(g->movecount);
	mlx_string_put(g->mlx, g->window, 5, 12, 0x00FF0000, moves);
	free(moves);
	return (0);
}
