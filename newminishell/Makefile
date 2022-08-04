NAME = minishell
CC = gcc
CFLAGS = -Wall -Wextra -Werror -lreadline -g
SRCS = main.c \
	utils.c		\
	ft_parser.c	\
	ft_parser2.c	\
	ft_execute.c	\
	ft_free.c		\

# colors for printing


OBJS= $(SRCS:.c=.o)
PRIN = ./libft/libft.a
RED = '\033[0;31m'
BUILTIN = ./builtin/builtin.a

all: $(PRIN) ${BUILTIN} ${NAME}

$(PRIN):
	@make -C libft/
$(BUILTIN):
	@make -C builtin/

$(NAME): $(OBJS) $(PRIN) $(BUILTIN)
	@$(CC) ${CFLAGS} $(OBJS) -o $(NAME) $(PRIN) $(BUILTIN)
	@echo "Minishell ready."

%.o: %.c
	@echo $(R)Complining: [$<]
	@${CC} -c $^ -o $@ -Wall -Werror -Wextra

clean:
	@rm -rf ${OBJS}
	@make clean -C builtin/
	@make clean -C libft/
	@echo [$(OBJS)]$(B)

fclean: clean
	@rm -rf ${NAME}
	@make fclean -C builtin/
	@make clean -C libft/
	@echo [$(NAME)]$(B)

re: fclean all

norm:
	norminette *.c

.PHONY: fclean re all clean