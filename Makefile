CC		= gcc
CFLAGS	= -Wall -Wextra -Werror

SERVER	= server
SRC_S	= server.c

CLIENT	= client
SRC_C	= client.c

all: $(SERVER) $(CLIENT)

$(SERVER):
	$(CC) $(CFLAGS) $(SRC_S) -o $@

$(CLIENT):
	$(CC) $(CFLAGS) $(SRC_C) -o $@

clean:
	rm -f $(SERVER) $(CLIENT)

fclean: clean

re: fclean all

.PHONY: all clean fclean re
