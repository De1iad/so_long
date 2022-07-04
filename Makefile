NAME	=	so_long
CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror
INCLUDE	=	-lX11 -lXext
SRCS	=	main.c input.c render.c map.c init.c exit.c enemy.c movement.c check.c image.c maps.c render_enemy.c assign_enemy.c $(wildcard ./gnl/*.c)
SRCS2	=	main.c input.c render.c map.c init.c exit.c enemy.c movement.c checkbonus.c image.c maps.c render_enemy.c assign_enemy.c $(wildcard ./gnl/*.c)
LIBFT	=	libft/
LIBMLX	=	minilibx-linux/

all:	$(NAME)

$(NAME): $(SRCS)
		make re -C $(LIBFT)
		make -C $(LIBMLX)
		gcc $(CFLAGS) $(SRCS) ./libft/libft.a ./minilibx-linux/libmlx.a $(INCLUDE) -o $(NAME)

bonus:

	make re -C $(LIBFT)
	make -C $(LIBMLX)
	gcc $(CFLAGS) $(SRCS2) ./libft/libft.a ./minilibx-linux/libmlx.a $(INCLUDE) -o $(NAME)

clean:
		rm -f *.o
		make clean -C $(LIBFT)
		make clean -C $(LIBMLX)

fclean: clean
		rm -f $(NAME)
		make fclean -C $(LIBFT)

re: fclean all