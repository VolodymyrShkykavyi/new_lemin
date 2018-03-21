NAME = visu-hex
CC = gcc
FLAGS =  -O2 #-Wall -Werror -Wextra
O_FILES = $(addprefix $(OBJ_DIR)/, $(C_FILES:$(SRC_DIR)/%.c=%.o))
C_FILES = $(addprefix $(SRC_DIR)/, main.c run_hooks.c read_data.c parse_room.c \
			support_func.c print_error.c tmp_debug.c \
			$(addprefix graphics/, init_img_struct.c init_mlx_and_img.c put_pixel_to_img.c))
OBJ_DIR = objects
SRC_DIR = src
INCLUDES =  -I includes/ -I ../libft/includes 
LIB_INCLUDES = -L./../libft -lft -lmlx -framework OpenGL -framework AppKit

all: $(NAME)
$(NAME): $(OBJ_DIR) $(O_FILES)
	@$(MAKE) -C ../libft
	$(CC) $(FLAGS) $(O_FILES) -o $(NAME) $(INCLUDES) $(LIB_INCLUDES)
	@echo "\033[34m$(NAME) compiled\033[0m"
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)
	mkdir -p $(OBJ_DIR)/graphics
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(FLAGS) -o $@ -c $< $(INCLUDES)
clean:
	rm -rf $(OBJ_DIR)
fclean: clean
	rm -f $(NAME)
re: fclean all
run:
	@make
	./visu-hex
