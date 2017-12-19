NAME = fdf
SRCS = srcs/main.c \
	   srcs/parsing.c \
	   srcs/hook.c \
	   srcs/init.c \
	   srcs/projection.c \
	   srcs/error.c \
	   srcs/draw.c \
	   srcs/color.c

OBJS = $(SRCS:srcs/%.c=%.o)
LIB = -L./minilibx_macos/ -lmlx -framework OpenGL -framework Appkit -L./libft/ -lft
CFLAGS = -Wall -Wextra -Werror -g
CC = gcc
RM = rm -f
I = -I./includes \
	-I./libft \

$(NAME):
	make -C libft/
	make -C minilibx_macos/
	$(CC) $(CFLAGS) $(I) -c $(SRCS)
	$(CC) -o $(NAME) $(OBJS) $(LIB)

all: $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
