
NAME = serialize

all: $(NAME)

$(NAME): main.cpp
	clang++ -Wall -Wextra -Werror -o $(NAME) main.cpp

clean:

fclean: clean
	@rm $(NAME)

re: fclean all
	