NAME = harlFilter
CC = g++
CFLASG = -Wall -Wextra -Werror -std=c++98 -g
SRCS = main.cpp Harl.cpp
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

clean:
	@rm -rf ${NAME}

fclean: clean
	@rm -rf ${NAME}

re: fclean all

.PHONY: fclean re all clean