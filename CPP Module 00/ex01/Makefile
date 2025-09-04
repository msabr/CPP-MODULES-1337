NAME = PhoneBook

CFLAGS = -Wall -Wextra -Werror -std=c++98

CC = c++

SRC =	PhoneBook.cpp\
		Contact.cpp\
		main.cpp

OBJS = $(SRC:.cpp=.o)

HEADERS = PhoneBook.hpp Contact.hpp

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