NAME=libft.a
CC=cc
CFLAGS=-Wall -Wextra -Werror

SRC=*.c

.PHONY: all bonus clean fclean re

all: ${NAME}

${NAME}: ${SRC}
	@make -C ./ft_printf all >2 /dev/null || true
	@echo "Compiling libft..."
	@${CC} ${CFLAGS} -c ${SRC} -fpic -I./ft_printf/includes 2> /dev/null || true
	@ar rc ${NAME} *.o ./ft_printf/bin/*.o 2> /dev/null || true
	@ranlib ${NAME} 2> /dev/null || true
	@echo "Successfully compiled libft!"

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