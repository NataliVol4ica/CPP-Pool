
NAME = whatever

all: $(NAME)

$(NAME): whatever.cpp
	clang++ -Wall -Wextra -Werror -o $(NAME) whatever.cpp

clean:

fclean: clean
	@rm $(NAME)

re: fclean all
	