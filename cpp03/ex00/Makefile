NAME = ClapTrap
CPP = c++ 
FLAGS = -Wall -Wextra -Werror -std=c++98

SRC = main.cpp ClapTrap.cpp
OBJ = main.o ClapTrap.o

all: $(NAME)

$(NAME): $(OBJ)
	$(CPP) $(FLAGS) -o $@ $^

%.o: %.cpp ClapTrap.hpp
	$(CPP) $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re