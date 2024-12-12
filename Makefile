SRC = 	gnl/get_next_line.c gnl/get_next_line_utils.c \
		srcs/so_long.c srcs/error.c srcs/parse_map.c srcs/map_check.c \
		srcs/dfs.c srcs/game_render_utils.c srcs/move_player.c
OBJ = $(SRC:.c=.o)
NAME = so_long
LIBFT = ./libft/libft.a

all: $(NAME)

$(NAME): $(OBJ)
	$(MAKE) -C ./libft/ --silent
	$(CC) $(OBJ) $(LIBFT) -fsanitize=address -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

%.o: %.c
	$(CC) -Wall -Wextra -Werror -I/usr/include -Imlx_linux -O3 -c $< -o $@

clean:
	$(MAKE) -C ./libft/ clean --silent
	$(RM) $(OBJ)

fclean: clean
	$(MAKE) -C ./libft/ fclean --silent
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
.SECONDARY: $(OBJ)
