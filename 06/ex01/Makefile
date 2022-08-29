CC := g++
CXXFLAGS := -Wall -Wextra -Werror -std=c++98
NAME := serialization

all: ${NAME}
${NAME}:

fclean:
	rm -f serialization *.dSYM

re: fclean serialization

debug: CXXFLAGS += -g
debug: re

.PHONY: fclean re debug