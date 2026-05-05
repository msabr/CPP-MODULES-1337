NAME = easyfind

CXXFLAGS = -Wall -Wextra -Werror -std=c++98

CXX = c++

SRC = main.cpp 

OBJS = $(SRC:.cpp=.o)

HEADERS =	easyfind.hpp

all: $(NAME)

$(NAME): $(OBJS)
		$(CXX) $(CXXFLAGS) $^ -o $@

%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: clean