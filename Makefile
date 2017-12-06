NAME = fdf
SRCS = main.c \

OBJS = $(SRCS:.c=.o)
LIB = -L/usr/X11/lib -lmlx -lXext -lX11
CFLAGS = -Wall -Wextra -Werror -I/usr/X11/include/
CC = gcc
RM = rm -f

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIB)

all: $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
