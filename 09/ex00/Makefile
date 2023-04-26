CXXFLAGS := -Wall -Werror -Wextra -std=c++98

CXX := c++

NAME := btc

SRC := src/main.cpp \
		src/BitcoinExchange.cpp

HDR := inc/BitcoinExchange.hpp

SRCDIR := src/

OBJDIR := obj/

OBJ := $(SRC:src/%.cpp=obj/%.o)

$(OBJDIR)%.o: ${SRCDIR}%.cpp
	$(CXX) $(CXXFLAGS) -Iinc/ -c $< -o $@

all: $(NAME)

$(NAME): $(OBJDIR) $(HDR) $(OBJ) 
	$(CXX) $(OBJ) -o $(NAME)

$(OBJDIR):
	@mkdir $(OBJDIR)

clean:
	@rm -r $(OBJDIR)

fclean: clean
	@rm -rf $(NAME) *.dSYM

re: fclean all

debug: CXX = clang++
debug: CXXFLAGS += -g -fno-limit-debug-info
debug: re

.PHONY: all clean fclean re