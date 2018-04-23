
NAME = array

all: $(NAME)

$(NAME): main.cpp Array.hpp 
	clang++ -Wall -Wextra -Werror main.cpp -I. -o $(NAME)

clean:

fclean: clean
	@rm $(NAME)

re: fclean all
	