NAME	=	so_long
CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror
INCLUDE	=	-L /usr/X11/lib -lX11 -lXext libft/libft.a libmlx.a
SRCS	=	main.c input.c render.c map.c init.c exit.c enemy.c movement.c check.c image.c maps.c render_enemy.c assign_enemy.c $(wildcard ./gnl/*.c)
SRCS2	=	main.c input.c render.c map.c init.c exit.c enemy.c movement.c checkbonus.c image.c maps.c render_enemy.c assign_enemy.c $(wildcard ./gnl/*.c)
LIBFT	=	libft/

all:	$(NAME)

$(NAME): $(SRCS)
		make re -C $(LIBFT)
		gcc $(CFLAGS) $(SRCS) $(INCLUDE) -o $(NAME)

bonus:

	make re -C $(LIBFT)
	gcc $(CFLAGS) $(SRCS2) $(INCLUDE) -o $(NAME)

clean:
		rm -f *.o
		make clean -C $(LIBFT)

fclean: clean
		rm -f $(NAME)
		make fclean -C $(LIBFT)

re: fclean all