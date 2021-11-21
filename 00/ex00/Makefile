NAME = megaphone
SRC = megaphone.cpp
CC = g++
CFLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(NAME)

fclean:
	rm -f $(NAME)

re: fclean all

.PHONY: all fclean re