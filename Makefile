FLAGS = -Werror -Wextra -Wall
NAME = monitor
SRC = src/monitor.c src/gnl_data.c src/sensor1.c
INCLUDES=libft/libft.a

all:
	@make -C libft/ all
	gcc -g $(SRC) -o $(NAME) $(FLAGS) $(INCLUDES)

clean:
	@make -C libft/ clean

fclean: clean
	/bin/rm -f $(NAME)
	@make -C libft/ fclean

re: fclean all