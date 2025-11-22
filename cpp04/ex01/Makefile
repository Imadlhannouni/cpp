NAME = Animal_b
CPP = c++ 
FLAGS = -Wall -Wextra -Werror -Wshadow -std=c++98 

SRC = main.cpp Cat.cpp Dog.cpp Animal.cpp Brain.cpp
OBJ = main.o Cat.o Dog.o Animal.o Brain.o

all: $(NAME)

$(NAME): $(OBJ)
	$(CPP) $(FLAGS) -o $@ $^

%.o: %.cpp Cat.hpp Dog.hpp Animal.hpp Brain.hpp
	$(CPP) $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re