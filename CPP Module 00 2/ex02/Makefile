# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msabr <msabr@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/28 23:57:08 by msabr             #+#    #+#              #
#    Updated: 2025/07/19 17:19:59 by msabr            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = log

CFLAGS = -Wall -Wextra -Werror -std=c++98

CC = c++

RM = rm -rf

SRC = Account.cpp tests.cpp

OBJS = $(SRC:.cpp=.o)

FILE = file.log

HEADER = Account.hpp

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

%.o: %.cpp $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)
	$(RM) $(FILE)

re: fclean all

run:
	./$(NAME) > $(FILE)

.PHONY: clean