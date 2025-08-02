# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msabr <msabr@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/28 23:57:08 by msabr             #+#    #+#              #
#    Updated: 2025/06/29 05:55:20 by msabr            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = PhoneBook

CFLAGS = -Wall -Wextra -Werror -std=c++98

CC = c++

RM = rm -rf

SRC =	PhoneBook.cpp\
		Contact.cpp\
		main.cpp

OBJS = $(SRC:.cpp=.o)

HEADER = PhoneBook.hpp Contact.hpp

all: $(NAME)

$(NAME): $(OBJS)
		$(CC) $(CFLAGS) $^ -o $@

%.o: %.cpp $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: clean

