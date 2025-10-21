NAME    = ex01
CFLAGS= -Wall -Wextra -Werror

SRCS    = ClapTrap.cpp ScavTrap.cpp main.cpp
OBJS    = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	c++ $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp ClapTrap.hpp ScavTrap.hpp
	c++ $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
