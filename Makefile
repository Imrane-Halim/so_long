FLAGS = -Wall -Wextra #-Werror
NAME = game
SRCS = $(wildcard srcs/*.c)
OBJ = $(SRCS:.c=.o)

all: $(NAME)

%.o: %.c
	$(CC) $(FLAGS) -I/usr/include -Imlx_linux -O3 -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(OBJ) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

clean:
	$(RM) *.o srcs/*.o

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONLY: all clean fclean re
