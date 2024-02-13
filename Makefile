NAME = so_long
NAME_BONUS = bonus
CC = cc
CFLAGS = -Wall -Wextra -Werror #-g3 -fsanitize=address
PATH_SRCS = ./srcs/
SRCS = main.c
OBJ = $(addprefix $(BUILD_DIR)/,$(SRCS:.c=.o))
SRCS_BONUS = 
OBJ_BONUS = $(addprefix $(BUILD_DIR)/,$(SRCS_BONUS:.c=.o))
BUILD_DIR = .build

all: libft $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) ./includes/libft/libft.a -o $@
	@echo "\ncompile done!\n"
	#@echo 'tape for exemple : ARG="5 3 4"; ./push_swap $$ARG'"\n"

bonus: all $(NAME_BONUS)

$(NAME_BONUS): $(OBJ_BONUS)
	@$(CC) $(CFLAGS) $(OBJ_BONUS) ./includes/libft/libft.a -o $@
	#@echo '\nchecker is ready for use too!'"\n"
	#@echo 'tape for exemple : ARG="5 3 4"; ./push_swap $$ARG | ./checker $$ARG'"\n"

$(BUILD_DIR)/%.o: $(PATH_SRCS)%.c Makefile
	@mkdir -p $(BUILD_DIR)
	@$(CC) $(CFLAGS) -MMD -MP -c $< -o $@ -I ./includes

-include $(OBJ:.o=.d) $(OBJ_BONUS:.o=.d)

libft:
	@make --no-print-directory -C includes/libft bonus

clean:
	@make --no-print-directory -C ./includes/libft clean
	@rm -rf $(BUILD_DIR)

fclean: clean
	@make --no-print-directory -C ./includes/libft fclean
	@rm -rf $(NAME) $(NAME_BONUS)

re : fclean
	@make --no-print-directory

.PHONY: all clean fclean re bonus libft