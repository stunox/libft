NAME=libft.a
CC=cc
CFLAGS=-Wall -Wextra -Werror

SRC_FILES=*.c
SRC_DIR=src
SRC_SUBDIRS=gnl io list memory string utils
SRC=$(addprefix ${SRC_DIR}/, $(addsuffix /${SRC_FILES}, ${SRC_SUBDIRS}))
INCLUDES = -I./includes
OBJ
GREEN = \033[0;32m
RED = \033[0;31m
BLUE = \033[0;34m
YELLOW = \033[0;33m
CYAN = \033[0;36m
MAGENTA = \033[0;35m
WHITE = \033[0;37m
BLACK = \033[0;30m
INVISIBLE = \033[8m
RESET = \033[0m

.PHONY: all bonus clean fclean re

all: ${NAME}

${NAME}: ${SRC}
	@make -C ${SRC_DIR}/ft_printf all >2 /dev/null || true
	@echo "${BLUE}Compiling libft...${RESET}"
	@${CC} ${CFLAGS} -c ${SRC} -fpic -I${SRC_DIR}/ft_printf/includes ${INCLUDES} 2> /dev/null || true
	@ar rc ${NAME} *.o ${SRC_DIR}/ft_printf/bin/*.o 2> /dev/null || true
	@ranlib ${NAME} 2> /dev/null || true
	@echo "${GREEN}Successfully compiled libft!${RESET}" || @echo "${RED}Failed to compile libft! ${RESET}"
	@echo "${INVISIBLE}"

clean:
	@rm -f *.o

fclean: clean
	@rm -f ${NAME}
	@make -C ${SRC_DIR}/ft_printf fclean

re: fclean all

# test: all
# 	${CC} ${CFLAGS} main.c ${NAME} -o test
# 	./test
# 	rm -f test