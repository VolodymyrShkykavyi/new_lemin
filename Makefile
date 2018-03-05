NAME = lem-in
CC = gcc
#FLAGS = -Wall -Werror -Wextra
OBJ_DIR = objects
SRC_DIR = src
O_FILES = $(addprefix $(OBJ_DIR)/, $(C_FILES:$(SRC_DIR)/%.c=%.o))
C_FILES = $(addprefix $(SRC_DIR)/, main.c read_file.c print_error.c \
			find_room.c get_ant_num.c parse_command.c parse_edge.c \
			parse_room.c)
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
	#$(MAKE) clean -C libft
	rm -rf $(OBJ_DIR)
fclean: clean
	#$(MAKE) fclean -C libft
	rm -f $(NAME)
re: fclean all