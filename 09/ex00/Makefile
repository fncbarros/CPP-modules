CXXFLAGS := -Wall -Werror -Wextra -std=c++98

CXX := c++

NAME := btc

SRC := src/main.cpp \
		src/BitcoinExchange.cpp

HDR := inc/BitcoinExchange.hpp

OBJDIR := obj/

SRCDIR := src/

OBJ := $(SRC:src/%.cpp=obj/%.o)

${OBJDIR}%.o: ${SRCDIR}%.cpp
	$(CXX) $(CXXFLAGS) -Iinc/ -c $< -o $@

all: $(NAME)

$(NAME): $(HDR) $(OBJDIR) $(OBJ) 
	$(CXX) $(OBJ) -o $(NAME)

${OBJDIR}:
	@mkdir ${OBJDIR}

clean:
	@rm -r obj

fclean: clean
	@rm -rf $(NAME) *.dSYM

re: fclean all

debug: CXX = clang++
debug: CXXFLAGS += -g -fno-limit-debug-info
debug: re

.PHONY: all clean fclean re