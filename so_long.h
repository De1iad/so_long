/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obibby <obibby@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 13:24:45 by obibby            #+#    #+#             */
/*   Updated: 2022/07/01 22:47:17 by obibby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "mlx.h"
# include <stdlib.h>
# include <fcntl.h>
# include "./gnl/get_next_line.h"
# include "./libft/libft.h"

typedef struct s_entity {
	char	id;
	char	*name;
	void	*imgw;
	void	*imgb;
	void	*imgcb;
	void	*imgcw;
	void	*imge;
	int		xcoord;
	int		ycoord;
}	t_entity;

typedef struct s_screen {
	void	*ptr;
	int		bpp;
	int		sline;
	int		endian;
	char	*addr;
}	t_screen;

typedef struct s_game {
	void		*mlx;
	void		*window;
	int			mapcount;
	int			totalmaps;
	char		**maps;
	int			max_x;
	int			max_y;
	char		**map;
	char		**omap;
	t_screen	*wscreen;
	t_entity	**entity;
	t_entity	*killer;
	int			randseedx;
	int			randseedy;
	int			movecount;
	int			victory;
	int			defeat;
	int			ccount;
	void		*wall_img;
	void		*floor_w;
	void		*floor_b;
	void		*collectwb;
	void		*collectbb;
	void		*exit;
	void		*playerwb;
	void		*playerbb;
	void		*player1wb;
	void		*player1bb;
	void		*player2wb;
	void		*player2bb;
	void		*eplayer;
	void		*pawnwb;
	void		*pawnbb;
	void		*knightwb;
	void		*knightbb;
	void		*bishopwb;
	void		*bishopbb;
	void		*castlewb;
	void		*castlebb;
	void		*queenwb;
	void		*queenbb;
}	t_game;

typedef enum e_size {
	SIZE = 34
}	t_size;

typedef enum e_map {
	FLOOR = '0',
	WALL = '1',
	COLLECT = 'C',
	EXIT = 'E',
	PLAYER = 'P',
	EPLAYER = 'L',
	QUEEN = 'Q',
	PAWN = 'R',
	KNIGHT = 'S'
}	t_map;

typedef enum e_keys {
	ESC = 53,
	UP = 13,
	LEFT = 0,
	DOWN = 1,
	RIGHT = 2,
	RESTART = 15
}	t_keys;

int				main(int argc, char **argv);
int				input(int key, t_game *g);
int				ft_exit(t_game *g, int code);
void			render_frame(t_game *g);
void			assign_images(t_game *g, int s);
char			**store_map(int fd, int lines);
int				createmap(t_game *g, int argc, char **argv, int lines);
int				error_write(char *c);
int				ft_move(int key, t_game *g);
void			ft_path(t_game *g, t_entity *p, int x, int y);
t_entity		**init_entity(t_game *g, int i, int x, int y);
void			render_black(t_game *g, int x, int y);
void			straight_move(t_entity *e, t_game *g, int x, int y);
void			diagonal_move(t_entity *e, t_game *g, int x, int y);
void			queen_move(t_entity *e, t_game *g, int x, int y);
void			render_white(t_game *g, int x, int y);
t_entity		*killer_init(t_game *g, t_entity *e);
int				randno(t_game *g);
void			max_coords(t_game *g);
int				check_map(t_game *g);
int				free_entity(t_game *g);
char			**free_map(char **map, char *str);
void			*create_img(t_game *g, int colour);
int				colourshift(int t, int r, int g, int b);
void			restart_game(t_game *g);
void			render_vicdef(t_game *g);
void			rand_smove(t_entity *e, t_game *g, int x, int y);
void			render_enemy(t_game *g, int x, int y, int col);
void			pawn_move(t_entity *e, t_game *g, int x, int y);
void			assign_eimages(t_game *g, int s);
void			enemy_type(t_entity *e, t_game *g, int x, int y);
void			free_images(t_game *g);
char			**init_maps(t_game *g);
void			next_level(t_game *g);
void			render_victory(t_game *g, char *moves, int x, int y);
void			render_defeat(t_game *g, char *moves, int x, int y);
void			knight_move(t_entity *e, t_game *g, int x, int y);
void			rand_knight(t_entity *e, t_game *g, int x, int y);
void			render_enemy(t_game *g, int x, int y, int col);
void			assign_knight(t_game *g, int i, int s);
void			assign_pawn(t_game *g, int i, int s);
void			assign_queen(t_game *g, int i, int s);

#endif