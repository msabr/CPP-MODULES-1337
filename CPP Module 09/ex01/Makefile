NAME = RPN

CXXFLAGS = -Wall -Wextra -Werror -std=c++98

CXX = c++

SRC = RPN.cpp main.cpp

OBJS = $(SRC:.cpp=.o)

HEADERS =	RPN.hpp

all: $(NAME)

$(NAME): $(OBJS)
		$(CXX) $(CXXFLAGS) $^ -o $@

%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean