NAME = megaphone
CPP = c++
FLAGS = -Wall -Wextra -Werror

SRC = megaphone.cpp
OBJ = megaphone.o

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