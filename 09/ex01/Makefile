NAME := RPN

CXX := c++

CXXFLAGS := -Wall -Wextra -Werror -std=c++98

SRC := src/main.cpp \
		src/RPN.cpp

INCLUDES := inc/

OBJ := $(SRC:%.cpp=%.o)

OBJDIR := obj/

%.o: %.cpp
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

.PHONY: all clean re debug
