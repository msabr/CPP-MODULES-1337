NAME = FixedPoint

CFLAGS = -Wall -Wextra -Werror -std=c++98

CC = c++

SRC = main.cpp Fixed.cpp

OBJS = $(SRC:.cpp=.o)

HEADERS = Fixed.hpp

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

.PHONY: clean fclean re all