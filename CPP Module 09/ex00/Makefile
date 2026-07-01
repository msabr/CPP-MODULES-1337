NAME = btc

CXXFLAGS = -Wall -Wextra -Werror -std=c++98

CXX = c++

SRC = 

OBJS = $(SRC:.cpp=.o)

HEADERS =	whatever.hpp

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