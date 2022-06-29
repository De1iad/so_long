NAME	=	libftprintf.a
CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror
SRCS	=	ft_char_write.c ft_flag_count.c ft_hexa_write.c ft_uint_write.c ft_int_write.c ft_printf.c ft_ptr_write.c ft_str_write.c $(wildcard ./libft/*.c)
OBJS	=	$(SRCS:.c=.o)
LIBFT	=	./libft

all:	$(NAME)

$(NAME): $(OBJS)
		make re -C $(LIBFT)
		ar -cr $(NAME) $(OBJS)

bonus: re

clean:
		rm -f *.o
		make clean -C $(LIBFT)

fclean: clean
		rm -f $(NAME)
		make fclean -C $(LIBFT)

re: fclean all