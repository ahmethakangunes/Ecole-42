SRCS_CL = client.c
SRCS_SR = server.c
SRCS_BCL = client_bonus.c
SRCS_BSR = server_bonus.c
SRCS = ft_printf.c ft_atoi.c
OBJS_SRCS = $(SRCS:.c=.o)
OBJS_CL = $(SRCS_CL:.c=.o) $(OBJS_SRCS)
OBJS_SR = $(SRCS_SR:.c=.o) $(OBJS_SRCS)
OBJS_BCL = $(SRCS_BCL:.c=.o) $(OBJS_SRCS)
OBJS_BSR = $(SRCS_BSR:.c=.o) $(OBJS_SRCS)
NAME_CL = client
NAME_SR = server
NAME_BSR = server_bonus
NAME_BCL = client_bonus
CFLAGS  = -Wall -Wextra -Werror

all: $(NAME_SR) $(NAME_CL)

$(NAME_SR): $(OBJS_SR)
	gcc $(CFLAGS) $(OBJS_SR) -o $(NAME_SR)

$(NAME_CL): $(OBJS_CL)
	gcc $(CFLAGS) $(OBJS_CL) -o $(NAME_CL)

$(NAME_BSR): $(OBJS_BSR)
	gcc $(CFLAGS) $(OBJS_BSR) -o $(NAME_BSR)

$(NAME_BCL): $(OBJS_BCL)
	gcc $(CFLAGS) $(OBJS_BCL) -o $(NAME_BCL)

bonus: $(NAME_BCL) $(NAME_BSR)

.c.o:
	gcc $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS_CL) $(OBJS_SR) $(OBJS_SRCS) $(OBJS_BCL) $(OBJS_BSR)

fclean: clean
	rm -rf $(NAME_SR) $(NAME_CL) $(NAME_BSR) $(NAME_BCL)

re: fclean all

.PHONY: all clean fclean re
