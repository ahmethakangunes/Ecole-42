NAME = minishell
CC = gcc
CFLAGS = -Wall -Wextra -Werror -lreadline -g
SRCS = main.c \
	utils.c \
	ft_minishell.c \
	ft_parser.c		\

# colors for printing
Y = "\033[33m"
R = "\033[31m"
G = "\033[32m"
B = "\033[34m"
X = "\033[0m"
UP = "\033[A"
CUT = "\033[K"

OBJS= $(SRCS:.c=.o)
PRIN = ./libft/libft.a
RED = '\033[0;31m'
all: $(PRIN)  ${NAME}
$(PRIN):
	@make -C ./libft

$(NAME): $(OBJS) $(PRIN)
	@$(CC) ${CFLAGS} $(OBJS) -o $(NAME) $(PRIN)
	@echo "\033[1;96mMinishell ready.\033[1;96m"

%.o: %.c
	@echo $(R)Complining: [$<]
	@${CC} -c $^ -o $@ -Wall -Werror -Wextra

clean:
	@rm -rf ${OBJS}
	@echo $(R)Removed [$(OBJS)]$(B)

fclean: clean
	@rm -rf ${NAME}
	@echo $(R)Removed [$(NAME)]$(B)

re: fclean all

norm:
	norminette *.c

.PHONY: fclean re all clean