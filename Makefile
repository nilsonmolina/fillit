NAME = 		fillit
FLAGS = 	-Wall -Wextra -Werror
C_FILES = 	main.c \
			verify.c \
			shapes.c
O_FILES =	ft_*.o

$(NAME):
	@gcc -o $(NAME) $(FLAGS) $(C_FILES)

all: $(NAME)

clean:
	@rm -rf $(O_FILES)

fclean: clean 
	@rm -rf $(NAME)

re: fclean all
