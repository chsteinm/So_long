NAME = so_long
NAME_BONUS = bonus
CC = cc
CFLAGS = -Wall -Wextra -Werror -g3 # -fsanitize=address
MLXFLAGS = -L ./minilibx-linux -lmlx -lXext -lX11
PATH_SRCS = ./srcs/
SRCS = main.c parse.c get_next_line.c check_win.c init_map.c move.c
OBJ = $(addprefix $(BUILD_DIR)/,$(SRCS:.c=.o))
SRCS_BONUS = 
OBJ_BONUS = $(addprefix $(BUILD_DIR)/,$(SRCS_BONUS:.c=.o))
BUILD_DIR = .build
LIBFT = ./includes/libft/libft.a

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(MLXFLAGS) -o $@
	@echo "\ncompile done!\n"

bonus: all $(NAME_BONUS)

$(NAME_BONUS): $(OBJ_BONUS)
	@$(CC) $(CFLAGS) $(OBJ_BONUS) $(LIBFT) -o $@
	#@echo '\nchecker is ready for use too!'"\n"

$(BUILD_DIR)/%.o: $(PATH_SRCS)%.c Makefile $(LIBFT)
	@mkdir -p $(BUILD_DIR)
	@$(CC) $(CFLAGS) -MMD -MP -c $< -o $@ -I ./includes

-include $(OBJ:.o=.d) $(OBJ_BONUS:.o=.d)

$(LIBFT): FORCE
	@make --no-print-directory -C includes/libft bonus

FORCE :

clean:
	@make --no-print-directory -C ./includes/libft clean
	@rm -rf $(BUILD_DIR)

fclean: clean
	@make --no-print-directory -C ./includes/libft fclean
	@rm -rf $(NAME) $(NAME_BONUS)

re : fclean
	@make --no-print-directory

.PHONY: all clean fclean re bonus FORCE