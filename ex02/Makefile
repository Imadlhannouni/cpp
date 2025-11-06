NAME = Account
CPP = c++ 
FLAGS = -Wall -Wextra -Werror -std=c++98

SRC = tests.cpp Account.cpp
OBJ = tests.o Account.o

all: $(NAME)

$(NAME): $(OBJ)
	$(CPP) $(FLAGS) -o $@ $^

%.o: %.cpp Account.hpp
	$(CPP) $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re