NAME = eval_expr
FILES = Fixed.class.cpp main.cpp

all: $(NAME)

$(NAME): $(FILES)
	clang++ -Wall -Wextra -Werror $(FILES) -I. -o $(NAME)

clean:

fclean: clean
	rm $(NAME)

re: fclean all
