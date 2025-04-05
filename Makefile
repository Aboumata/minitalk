CC		= cc
CFLAGS	= -Wall -Wextra -Werror

NAME_SERVER	= server
NAME_CLIENT	= client

SRC_SERVER	= server.c
SRC_CLIENT	= client.c ft_atoi.c

all: $(NAME_SERVER) $(NAME_CLIENT)

$(NAME_SERVER):
	$(CC) $(CFLAGS) $(SRC_SERVER) -o $(NAME_SERVER)

$(NAME_CLIENT):
	$(CC) $(CFLAGS) $(SRC_CLIENT) -o $(NAME_CLIENT)

clean:
	rm -f $(NAME_SERVER) $(NAME_CLIENT)

fclean: clean

re: fclean all

.PHONY: all clean fclean re
