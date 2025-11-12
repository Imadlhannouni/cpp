NAME = Fixed
CPP = c++ 
FLAGS = -Wall -Wextra -Werror -std=c++98

SRC = main.cpp Fixed.cpp Point.cpp bsp.cpp
OBJ = main.o Fixed.o Point.o bsp.o

all: $(NAME)

$(NAME): $(OBJ)
	$(CPP) $(FLAGS) -o $@ $^

%.o: %.cpp Fixed.hpp
	$(CPP) $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re