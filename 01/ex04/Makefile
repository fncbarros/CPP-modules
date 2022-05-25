SRC := ${wildcard *.cpp}

OBJ := ${SRC:%.cpp=obj/%.o}

CC := g++

CFLAGS := -Wall -Wextra -Werror -std=c++98

OBJDIR := obj/

NAME := fake_sed

${OBJDIR}%.o: %.cpp
	${CC} ${CFLAGS} -c $< -o $@

all: ${NAME}

${NAME}: ${OBJDIR} ${OBJ}
	${CC} ${CFLAGS} ${OBJDIR}/*.o -o ${NAME}

${OBJDIR}:
	mkdir ${OBJDIR}

debug:	CFLAGS += -g
debug:	re

clean:
	@rm -rf ${OBJDIR}

fclean: clean
	@rm -f ${NAME} *.dSYM *.replace

re: fclean all

.PHONY: all clean fclean re debug
