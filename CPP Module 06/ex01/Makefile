NAME = Serialization

CPP = c++

CFLAGS = -Wall -Wextra -Werror -std=c++98

INCLUDES = serializer.hpp

SRCS = serializer.cpp main.cpp

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