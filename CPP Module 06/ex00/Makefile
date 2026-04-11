NAME = ScalarConverter

CPP = c++

CFLAGS = -Wall -Wextra -Werror -std=c++98

INCLUDES = ScalarConverter.hpp

SRCS = ScalarConverter.cpp main.cpp helpers.cpp

OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CPP) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp $(INCLUDES)
	$(CPP) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean