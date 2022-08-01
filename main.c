/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obibby <obibby@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 12:41:16 by obibby            #+#    #+#             */
/*   Updated: 2022/08/01 19:48:22 by obibby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	error_write(char *c)
{
	ft_printf("Error\n%s\n", c);
	return (1);
}

void	next_level(t_game *g)
{
	if (g->mapcount == g->totalmaps)
		ft_exit(g, 4);
	mlx_destroy_window(g->mlx, g->window);
	free_map(g->map, NULL);
	free_map(g->omap, NULL);
	if (createmap(g, 2, g->maps + g->mapcount, 0) == 1)
		ft_exit(g, 2);
	g->mapcount++;
	max_coords(g);
	g->window = mlx_new_window(g->mlx, ((g->max_x + 1) * 34) + 2,
			((g->max_y + 1) * 34) + 2, "so_long");
	mlx_hook(g->window, 17, 0, ft_exit, g);
	mlx_key_hook(g->window, input, g);
	restart_game(g);
}

int	init_game(t_game *g, int argc, char **argv)
{
	g->mlx = mlx_init();
	if (!g->mlx)
		ft_exit(g, error_write("mlx_init failed."));
	if (createmap(g, argc, argv, 0) == 1)
		ft_exit(g, 2);
	g->entity = init_entity(g, 1, 0, 0);
	assign_images(g, 34);
	max_coords(g);
	g->wscreen = create_img(g, colourshift(0, 255, 255, 255));
	g->movecount = 0;
	g->victory = 0;
	g->defeat = 0;
	g->ccount = 0;
	g->mapcount = 0;
	if (check_map(g) == 1)
		ft_exit(g, 3);
	g->maps = init_maps(g);
	g->window = mlx_new_window(g->mlx, ((g->max_x + 1) * 34) + 2,
			((g->max_y + 1) * 34) + 2, "so_long");
	return (0);
}

int	main(int argc, char **argv)
{
	t_game		g;

	init_game(&g, argc, argv);
	mlx_hook(g.window, 17, 0, ft_exit, &g);
	mlx_expose_hook(g.window, render_frame, &g);
	mlx_key_hook(g.window, input, &g);
	render_frame(&g);
	mlx_loop(g.mlx);
	return (0);
}
