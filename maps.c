/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obibby <obibby@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 17:01:03 by obibby            #+#    #+#             */
/*   Updated: 2022/04/26 00:07:14 by obibby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**init_maps(t_game *g)
{
	char	**maps;

	maps = ft_calloc(4, sizeof(char *));
	if (!maps)
		ft_exit(g, 3);
	maps[1] = "maps/map2.ber";
	maps[2] = "maps/map3.ber";
	maps[3] = "maps/map4.ber";
	g->totalmaps = 3;
	return (maps);
}

void	render_victory(t_game *g, char *moves, int x, int y)
{
	mlx_put_image_to_window(g->mlx, g->window, g->wscreen->ptr, 17, 17);
	mlx_string_put(g->mlx, g->window, x - 17, y, 0xFF00, "VICTORY!");
	mlx_string_put(g->mlx, g->window, x - 17, y + 34, 0xFF00, "Moves:");
	mlx_string_put(g->mlx, g->window, x + 25, y + 34, 0xFF00, moves);
	mlx_string_put(g->mlx, g->window, x - 17, y + 68, 0xFF00,
		"Press n for next map");
}

void	render_defeat(t_game *g, char *moves, int x, int y)
{
	mlx_string_put(g->mlx, g->window, x - 17, y - 34, 0xFF0000, "DEFEAT!");
	mlx_string_put(g->mlx, g->window, x - 17, y, 0xFF0000, "Defeated by");
	mlx_string_put(g->mlx, g->window, x + 55, y, 0xFF0000, g->killer->name);
	mlx_string_put(g->mlx, g->window, x - 17, y + 34, 0xFF0000, "Moves:");
	mlx_string_put(g->mlx, g->window, x + 25, y + 34, 0xFF0000, moves);
	mlx_string_put(g->mlx, g->window, x - 17, y + 68, 0xFF0000,
		"Press r to retry");
}
