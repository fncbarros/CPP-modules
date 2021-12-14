SRC = ${wildcard *.cpp}

OBJ = ${SRC:%.cpp=%.o}

CC = g++

CFLAGS = -Wall -Wextra -Werror -std=c++98 -g

OBJDIR = obj

INC = -I inc/

NAME = phonebook

%.o: %.cpp
	${CC} ${CFLAGS} ${INC} -c $< -o $@

all: ${NAME}

${NAME}: ${OBJ} ${OBJDIR}
	${CC} ${CFLAGS} ${OBJDIR}/*.o -o ${NAME}

${OBJDIR}: ${OBJ}
	mkdir ${OBJDIR}
	mv ${OBJ} ${OBJDIR}

clean:
	@rm -rf ${OBJDIR}

fclean: clean
	@rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re
