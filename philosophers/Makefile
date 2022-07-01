NAME = philo
CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRCS = fork.c \
	ft_atoi.c \
	main.c \
	mutexandfork.c \
	setup.c		\
	start.c	\
	utils.c	\
	utils2.c

# colors for printing
Y = "\033[33m"
R = "\033[31m"
G = "\033[32m"
B = "\033[34m"
X = "\033[0m"
UP = "\033[A"
CUT = "\033[K"

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