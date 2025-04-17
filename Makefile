CC			= cc
CFLAGS		= -Wall -Wextra -Werror

NAME_SERVER	= server
NAME_CLIENT	= client
SRC_SERVER	= server.c ft_atoi.c ft_putnbr_fd.c
SRC_CLIENT	= client.c ft_atoi.c ft_putnbr_fd.c

BONUS_SERVER	= server_bonus
BONUS_CLIENT	= client_bonus
SRC_BONUS_SERVER	= bonus/server_bonus.c bonus/ft_atoi_bonus.c bonus/ft_putnbr_fd_bonus.c
SRC_BONUS_CLIENT	= bonus/client_bonus.c bonus/ft_atoi_bonus.c bonus/ft_putnbr_fd_bonus.c

all: $(NAME_SERVER) $(NAME_CLIENT)

$(NAME_SERVER): $(SRC_SERVER)
	$(CC) $(CFLAGS) $(SRC_SERVER) -o $(NAME_SERVER)

$(NAME_CLIENT): $(SRC_CLIENT)
	$(CC) $(CFLAGS) $(SRC_CLIENT) -o $(NAME_CLIENT)

bonus: $(BONUS_SERVER) $(BONUS_CLIENT)

$(BONUS_SERVER): $(SRC_BONUS_SERVER)
	$(CC) $(CFLAGS) $(SRC_BONUS_SERVER) -o $(BONUS_SERVER)

$(BONUS_CLIENT): $(SRC_BONUS_CLIENT)
	$(CC) $(CFLAGS) $(SRC_BONUS_CLIENT) -o $(BONUS_CLIENT)

clean:
	rm -f $(NAME_SERVER) $(NAME_CLIENT) $(BONUS_SERVER) $(BONUS_CLIENT)

fclean: clean

re: fclean all

.PHONY: all clean fclean re bonus
