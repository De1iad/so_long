NAME	=	so_long
CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror
INCLUDE	=	-lmlx -lX11 -lXext
SRCS	=	main.c input.c render.c map.c init.c exit.c enemy.c movement.c check.c image.c maps.c render_enemy.c assign_enemy.c $(wildcard ./gnl/*.c)
SRCS2	=	main.c input.c render.c map.c init.c exit.c enemy.c movement.c checkbonus.c image.c maps.c render_enemy.c assign_enemy.c $(wildcard ./gnl/*.c)
FTP		=	ftprintf/

all:	$(NAME)

$(NAME): $(SRCS)
		make re -C $(FTP)
		gcc $(CFLAGS) $(SRCS) ./ftprintf/libftprintf.a $(INCLUDE) -o $(NAME)

bonus:

	make re -C $(FTP)
	gcc $(CFLAGS) $(SRCS2) ./ftprintf/libftprintf.a $(INCLUDE) -o $(NAME)

clean:
		rm -f *.o
		make clean -C $(FTP)

fclean: clean
		rm -f $(NAME)
		make fclean -C $(FTP)

re: fclean all