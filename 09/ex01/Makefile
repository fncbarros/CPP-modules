NAME := RPN

CXX := c++

CXXFLAGS := -Wall -Wextra -Werror -std=c++98

SRCS := src/main.cpp \
		src/RPN.cpp

INCLUDES := inc/

all: $(NAME)

$(NAME):
	$(CXX) $(CXXFLAGS) -I$(INCLUDES) $(SRCS)  -o $(NAME)

clean:
fclean: clean
	rm $(NAME)
re: fclean all

debug: CXXFLAGS += -g
debug: re

.PHONY: all clean re debug