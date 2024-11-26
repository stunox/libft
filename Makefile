NAME=libft.a
CC=cc
CFLAGS=-Wall -Wextra -Werror

SRC=*.c

GREEN = \033[0;32m
RED = \033[0;31m
BLUE = \033[0;34m
YELLOW = \033[0;33m
CYAN = \033[0;36m
MAGENTA = \033[0;35m
WHITE = \033[0;37m
RESET = \033[0m

.PHONY: all bonus clean fclean re

all: ${NAME}

${NAME}: ${SRC}
	@make -C ./ft_printf all >2 /dev/null || true
	@echo "${BLUE}Compiling libft...${RESET}"
	@${CC} ${CFLAGS} -c ${SRC} -fpic -I./ft_printf/includes 2> /dev/null || true
	@ar rc ${NAME} *.o ./ft_printf/bin/*.o 2> /dev/null || true
	@ranlib ${NAME} 2> /dev/null || true
	@echo "${GREEN}Successfully compiled libft!${RESET}" || @echo "${RED}Failed to compile libft! ${RESET}"

clean:
	@rm -f *.o

fclean: clean
	@rm -f ${NAME}
	@make -C ./ft_printf fclean

re: fclean all

# test: all
# 	${CC} ${CFLAGS} main.c ${NAME} -o test
# 	./test
# 	rm -f test