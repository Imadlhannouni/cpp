NAME = phonebook
CPP = c++ 
FLAGS = -Wall -Wextra -Werror -std=c++98

SRC = PhoneBook.cpp Contact.cpp main.cpp
OBJ = PhoneBook.o Contact.o main.o

all: $(NAME)

$(NAME): $(OBJ)
	$(CPP) $(FLAGS) -o $@ $^

%.o: %.cpp Contact.hpp PhoneBook.hpp
	$(CPP) $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re