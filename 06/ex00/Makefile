SRC := ${wildcard src/*.cpp}

OBJ := ${SRC:src/%.cpp=obj/%.o}

CC := c++

CFLAGS := -Wall -Wextra -Werror -std=c++98

OBJDIR := obj/

SRCDIR := src/

HDIR := inc/

INC := -I ${HDIR}

NAME := convert

${OBJDIR}%.o: ${SRCDIR}%.cpp
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