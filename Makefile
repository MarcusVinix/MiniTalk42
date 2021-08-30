PATH_SRC = ./src/
PATH_OBJ = ./objs/
PATH_LIBFT = ./42libft/
LIBFT = $(PATH_LIBFT)libft.a
CLIENT = client
SERVER = server

CC = clang
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

all: $(LIBFT) $(CLIENT) $(SERVER)

$(LIBFT):
	@make -C $(PATH_LIBFT)

$(CLIENT):
	$(CC) $(CFLAGS) client.c $(LIBFT) -o $(CLIENT)

$(SERVER):
	$(CC) $(CFLAGS) server.c $(LIBFT) -o $(SERVER)

#
#server:
#	$(CC) $(CFLAGS) server.c -o server
#
#client:
#	$(CC) $(CFLAGS) client.c -o client

clean:
	$(RM) $(OBJS)

fclean:	clean
	make fclean -C $(PATH_LIBFT)
	$(RM) server client

re: fclean all

git:
	git add .
	git commit -m "starting the project"