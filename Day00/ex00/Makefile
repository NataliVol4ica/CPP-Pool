NAME = megaphone
FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): megaphone.cpp
	clang++ $(FLAGS) megaphone.cpp -o megaphone

clean:
	@rm megaphone

fclean: clean

re: fclean all
