SRC = ${wildcard *.cpp}

HEADER = ${wildcard inc/*.hpp}

OBJ = ${SRC:%.cpp=obj/%.o}

CC = g++

CFLAGS = -Wall -Wextra -Werror -std=c++98 -g

OBJDIR = obj/

INC = -I inc/

NAME = phonebook

${OBJDIR}%.o: %.cpp
	${CC} ${CFLAGS} ${INC} -c $< -o $@

all: ${NAME}

${NAME}: ${OBJDIR} ${OBJ} ${HEADER}
	${CC} ${CFLAGS} ${OBJDIR}/*.o -o ${NAME}

${OBJDIR}:
	mkdir ${OBJDIR}

clean:
	@rm -rf ${OBJDIR}

fclean: clean
	@rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re
