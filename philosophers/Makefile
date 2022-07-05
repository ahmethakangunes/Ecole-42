NAME = philo
CC = gcc
CFLAGS = -Wall -Wextra -Werror -fsanitize=thread
R = "\033[31m"
G = "\033[32m"
SRCS = fork.c \
	ft_atoi.c \
	main.c \
	mutexandfork.c \
	setup.c		\
	start.c		\
	die.c		\
	ft_exit.c   \
	utils.c

OBJS= $(SRCS:.c=.o)
all: ${NAME}


$(NAME): $(OBJS)
	@$(CC) ${CFLAGS} $(OBJS) -o $(NAME)
	@echo $(R)[COMPILING DONE]

%.o: %.c

	@echo $(G)Compiling: [$<]
	@${CC} -c $^ -o $@ -Wall -Werror -Wextra

clean:
	@rm -rf ${OBJS}

fclean: clean
	@rm -rf ${NAME}

re: fclean all

norm:
	norminette *.c

.PHONY: fclean re all clean