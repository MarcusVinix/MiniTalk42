PATH_SRC = ./src/
CLIENT = client
SERVER = server

UTILS = ./utils.c
FILES_S = ./server.c
FILES_C = ./client.c

OBJ_UTILS = $(UTILS:.c=.o)
OBJ_SERVER = $(FILES_S:.c=.o)
OBJ_CLIENT = $(FILES_C:.c=.o)

CC = clang
CFLAGS = -Wall -Wextra -Werror -fsanitize=address
RM = rm -rf

all: $(CLIENT) $(SERVER)


$(CLIENT): $(OBJ_CLIENT) $(OBJ_UTILS)
	$(CC) $(CFLAGS) $(OBJ_CLIENT)  $(OBJ_UTILS) -o $(CLIENT)

$(SERVER): $(OBJ_SERVER) $(OBJ_UTILS)
	$(CC) $(CFLAGS) $(OBJ_SERVER) $(OBJ_UTILS) -o $(SERVER)

clean:
	$(RM) $(OBJS)

fclean:	clean
	$(RM) server client

re: fclean all

git:
	git add .
	git commit -m "send a signal to confirm message received"
	git push origin master
