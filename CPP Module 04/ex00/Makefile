NAME = Animal

CFLAGS = -Wall -Wextra -Werror -std=c++98

CC = c++

SRC =	main.cpp Animal.cpp Dog.cpp Cat.cpp\
		WrongAnimal.cpp WrongCat.cpp

OBJS = $(SRC:.cpp=.o)

HEADERS =	Animal.hpp Dog.hpp Cat.hpp\
			WrongAnimal.hpp WrongCat.hpp

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