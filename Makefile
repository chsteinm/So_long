NAME = so_long
CC = cc
CFLAGS = -Wall -Wextra -Werror #-g3 -fsanitize=address
MLXFLAGS = -L ./minilibx-linux -lmlx -lXext -lX11
PATH_SRCS = ./srcs/
SRCS = main.c parse.c get_next_line.c check_win.c init_map.c move.c
OBJ = $(addprefix $(BUILD_DIR)/,$(SRCS:.c=.o))
BUILD_DIR = .build
LIBFT = ./includes/libft/libft.a
MLX = ./minilibx-linux/libmlx.a ./minilibx-linux/libmlx_Linux.a

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT) $(MLX)
	@$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(MLXFLAGS) -o $@
	@echo "\ncompile done!\n"
	@echo 'Tape for example "./so_long Ressources/Maps/classic.ber"'"\n"

$(BUILD_DIR)/%.o: $(PATH_SRCS)%.c Makefile
	@mkdir -p $(BUILD_DIR)
	@$(CC) $(CFLAGS) -MMD -MP -c $< -o $@ -I ./includes

-include $(OBJ:.o=.d) $(OBJ_BONUS:.o=.d)

$(LIBFT): FORCE
	@make --no-print-directory -C ./includes/libft bonus

$(MLX): FORCE
	@make --no-print-directory -C ./minilibx-linux

norm:
	norminette ./srcs ./includes

FORCE:

clean:
	@make --no-print-directory -C ./includes/libft clean
	@make --no-print-directory -C ./minilibx-linux clean
	@rm -rf $(BUILD_DIR)

fclean: clean
	@make --no-print-directory -C ./includes/libft fclean
	@rm -rf $(NAME) $(NAME_BONUS)

re: fclean
	@make --no-print-directory

.PHONY: all clean fclean re FORCE norm