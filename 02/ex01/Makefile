SRC := ${wildcard *.cpp}

OBJ := ${SRC:%.cpp=obj/%.o}

CC := g++

CFLAGS := -Wall -Wextra -Werror -std=c++98 -lm

OBJDIR := obj/

HDIR := inc/

INC := -I ${HDIR}

NAME := Fixed

${OBJDIR}%.o: %.cpp
	${CC} ${CFLAGS} ${INC} -c $< -o $@

all: ${NAME}

${NAME}: ${OBJDIR} ${OBJ} ${HDIR}
	${CC} ${CFLAGS} ${OBJDIR}/*.o -o ${NAME}

${OBJDIR}:
	mkdir ${OBJDIR}

debug:	CFLAGS += -g
debug:	re

clean:
	@rm -rf ${OBJDIR}

fclean: clean
	@rm -f ${NAME} *.dSYM

re: fclean all

.PHONY: all clean fclean re debug
