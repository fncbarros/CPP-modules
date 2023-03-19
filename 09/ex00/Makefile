CXXFLAGS := -Wall -Werror -Wextra -std=c++98

CC := c++

NAME := btc

SRC := src/main.cpp \
		src/BitcoinExchange.cpp

HDR := inc/BitcoinExchange.hpp

OBJ := $(SRC:src/%.cpp=obj/%.o)

obj/%.o: src/%.cpp
	@mkdir obj
	$(CC) $(CXXFLAGS) $(HDR) -c $< -o $@

all: $(NAME)

$(NAME): $(HDR) $(OBJ)
	$(CC) -Iinc $(OBJ) -o $(NAME)

clean:
	@rm -rf obj

fclean: clean
	@rm -rf $(NAME) *.dSYM

re: fclean all

debug: CXXFLAGS += -g
debug: re

.PHONY: all clean fclean re