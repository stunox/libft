NAME=libft.a
CC=cc
CFLAGS=-Wall -Wextra -Werror

SRC=*.c

.PHONY: all bonus clean fclean re

all: ${NAME}

${NAME}: ${SRC}
	make -C ./ft_printf all
	${CC} ${CFLAGS} -c ${SRC} -fpic -I./ft_printf/includes
	ar rc ${NAME} *.o ./ft_printf/bin/*.o
	ranlib ${NAME}

clean:
	rm -f *.o
	make -C ./ft_printf clean

fclean: clean
	rm -f ${NAME}
	make -C ./ft_printf fclean

re: fclean all

# test: all
# 	${CC} ${CFLAGS} main.c ${NAME} -o test
# 	./test
# 	rm -f test