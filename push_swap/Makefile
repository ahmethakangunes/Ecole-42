NAME = push_swap
CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRCS = control.c \
	fivearg.c \
	ft_atoi.c \
	ft_split.c \
	main.c \
	radix.c		\
	setup.c	\
	threearg.c	\
	utils.c	\
	utils2.c	\


OBJS= $(SRCS:.c=.o)
PRIN = ./ft_printf/libftprintf.a
all: $(PRIN)  ${NAME}
$(PRIN):
	@make -C ./ft_printf


$(NAME): $(OBJS) $(PRIN)
	@$(CC) ${CFLAGS} $(OBJS) -o $(NAME) $(PRIN)

%.o: %.c
	@echo $(R)Complining: [$<]
	@${CC} -c $^ -o $@ -Wall -Werror -Wextra

clean:
	@rm -rf ${OBJS}
	@make clean -C ft_printf/

fclean: clean
	@rm -rf ${NAME}
	@make fclean -C ft_printf/

re: fclean all

.PHONY: fclean re all clean