NAME := PmergeMe

CXX := c++

CXXFLAGS := -Wall -Wextra -Werror -std=c++98

SRC := src/main.cpp \
		src/PmergeMe.cpp

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

debug: CXXFLAGS += -g
debug: re

.PHONY: all clean re debug
