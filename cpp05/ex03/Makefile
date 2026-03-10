NAME = Bureaucrat
CPP = c++ 
FLAGS = -Wall -Wextra -Werror -std=c++98

SRC = main.cpp Bureaucrat.cpp AForm.cpp ShrubberyCreationForm.cpp RobotomyRequestForm.cpp PresidentialPardonForm.cpp Intern.cpp
OBJ = main.o Bureaucrat.o AForm.o ShrubberyCreationForm.o RobotomyRequestForm.o PresidentialPardonForm.o Intern.o

all: $(NAME)

$(NAME): $(OBJ)
	$(CPP) $(FLAGS) -o $@ $^

%.o: %.cpp
	$(CPP) $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re