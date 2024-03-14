CC = @gcc
NAME = philo
CFLAGS = -Wall -Wextra -Werror
SRCS = philo.c utils.c philo_life_cycle.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)
	
$(NAME): $(OBJS)
	@gcc $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	@rm -rf $(OBJS)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re