NAME=libftprintf.a
CC=gcc
CFLAGS=-Wall -Wextra -Werror

SRC_DIR=src
BIN_DIR=bin
INC_DIR=includes
SRC_FILES= \
	arg_handler.c \
	conversion.c \
	flag_handler.c \
	ft_printf.c \
	helper.c \
	number_utils.c \
	output.c \
	parser.c 
SRC=$(addprefix $(SRC_DIR)/, $(SRC_FILES))
OBJ=$(addprefix $(BIN_DIR)/, $(SRC_FILES:.c=.o))

all: $(NAME)

$(NAME): $(OBJ)
	@ar rcs $(NAME) $(OBJ) 2> /dev/null || true

$(BIN_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(BIN_DIR) 2> /dev/null || true
	@$(CC) $(CFLAGS) -I $(INC_DIR) -c $< -o $@ 2> /dev/null || true

clean:
	@rm -rf $(BIN_DIR) 2> /dev/null || true

fclean: clean
	@rm -f $(NAME) 2> /dev/null || true

re: fclean all

bonus: all

.PHONY: all clean fclean re bonus

# test: $(NAME)
# 	$(CC) -I $(INC_DIR) main.c $(NAME) -o test
# 	./test
# 	rm -f test