NAME = lem-in
CC = gcc
FLAGS = -Wall -Werror -Wextra  -O3
OBJ_DIR = objects
SRC_DIR = src
O_FILES = $(addprefix $(OBJ_DIR)/, $(C_FILES:$(SRC_DIR)/%.c=%.o))
C_FILES = $(addprefix $(SRC_DIR)/, main.c read_file.c print_error.c \
			parse_room.c  parse_edge.c support_func.c valid_and_set_weight.c \
			tmp_debug.c find_ways.c save_ways.c)
INCLUDES = -I libft/includes -I includes/

all: $(NAME)
$(NAME): $(OBJ_DIR) $(O_FILES)
	$(MAKE) -C libft
	$(CC) $(FLAGS) $(O_FILES) -o $(NAME) $(INCLUDES) -L./libft -lft
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(FLAGS) -o $@ -c $< $(INCLUDES)
clean:
	$(MAKE) clean -C libft
	rm -rf $(OBJ_DIR)
fclean: clean
	$(MAKE) fclean -C libft
	rm -f $(NAME)
re: fclean all
