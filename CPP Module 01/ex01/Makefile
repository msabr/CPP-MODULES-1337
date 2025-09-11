NAME = hordeZombies

CFLAGS = -Wall -Wextra -Werror -std=c++98

CC = c++

SRC = main.cpp Zombie.cpp zombieHorde.cpp

OBJS = $(SRC:.cpp=.o)

HEADERS = Zombie.hpp

all: $(NAME)

$(NAME): $(OBJS)
		$(CC) $(CFLAGS) $^ -o $@

%.o: %.cpp $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: clean