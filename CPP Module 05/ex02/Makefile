NAME = Bureaucrat

CXXFLAGS = -Wall -Wextra -Werror -std=c++98

CXX = c++

SRC = main.cpp	Bureaucrat.cpp AForm.cpp ShrubberyCreationForm.cpp\
				PresidentialPardonForm.cpp RobotomyRequestForm.cpp

OBJS = $(SRC:.cpp=.o)

HEADERS =	Bureaucrat.hpp AForm.hpp ShrubberyCreationForm.hpp\
			PresidentialPardonForm.hpp RobotomyRequestForm.hpp

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