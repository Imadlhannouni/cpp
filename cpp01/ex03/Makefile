NAME = violence
CPP = c++ 
FLAGS = -Wall -Wextra -Werror -std=c++98

SRC = HumanA.cpp HumanB.cpp Weapon.cpp main.cpp
OBJ = HumanA.o HumanB.o Weapon.o main.o

all: $(NAME)

$(NAME): $(OBJ) Weapon.hpp HumanA.hpp HumanB.hpp
	$(CPP) $(FLAGS) -o $@ $^

%.o: %.cpp Zombie.hpp
	$(CPP) $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re