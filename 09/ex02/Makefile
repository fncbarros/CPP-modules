NAME := PmergeMe

CXX := c++

CXXFLAGS := -Wall -Wextra -Werror #-std=c++98

SRC := src/main.cpp \
		src/PmergeMe.cpp

INCLUDES := inc/

OBJ := $(SRC:%.cpp=%.o)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -Iinc/ -c $< -o $@

all: $(NAME)

$(NAME): $(HDR) $(OBJ)
	$(CXX) $(OBJ) -o $(NAME)

clean:
	rm src/*.o
fclean: clean
	rm $(NAME)
re: fclean all

debug: CXXFLAGS += -g
debug: re

.PHONY: all clean re debug
