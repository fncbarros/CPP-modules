CXXFLAGS := -Wall -Werror -Wextra -std=c++98

CC := c++

NAME := btc

SRC := src/main.cpp \
		src/BitcoinExchange.cpp

HDR := inc/BitcoinExchange.hpp

OBJDIR := obj/

SRCDIR := src/

OBJ := $(SRC:src/%.cpp=obj/%.o)

${OBJDIR}%.o: ${SRCDIR}%.cpp
	$(CC) $(CXXFLAGS) -Iinc/ -c $< -o $@

all: $(NAME)

$(NAME): $(HDR) $(OBJDIR) $(OBJ)
	$(CC) $(OBJ) -o $(NAME)

${OBJDIR}:
	mkdir ${OBJDIR}

clean:
	@rm -rf obj

fclean: clean
	@rm -rf $(NAME) *.dSYM

re: fclean all

debug: CXXFLAGS += -g
debug: re

.PHONY: all clean fclean re