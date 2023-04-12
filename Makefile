CC = cc
CFLAGS = -Wall -Wextra -Werror
LIBFT_DIR = lib/libft

# List of source files
CLIENT_SRCS = src/client.c
SERVER_SRCS = src/server.c

# List of object files to build
CLIENT_OBJS = $(CLIENT_SRCS:.c=.o)
SERVER_OBJS = $(SERVER_SRCS:.c=.o)

# Build both the client and server executables
all: $(LIBFT_DIR)/libft.a client server

# Build the client executable
client: $(CLIENT_OBJS) $(LIBFT_DIR)/libft.a
	$(CC) $(CFLAGS) $(CLIENT_OBJS) -L$(LIBFT_DIR) -lft -o $@

# Build the server executable
server: $(SERVER_OBJS) $(LIBFT_DIR)/libft.a
	$(CC) $(CFLAGS) $(SERVER_OBJS) -L$(LIBFT_DIR) -lft -o $@

# Build the libft library
$(LIBFT_DIR)/libft.a:
	$(MAKE) -C $(LIBFT_DIR) all

# Rule to build object files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Remove object files and executables
clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	$(RM) client server $(CLIENT_OBJS) $(SERVER_OBJS)

# Remove object files, executables, and the libft library
fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean

# Rebuild the project from scratch
re: fclean all

.PHONY: all clean fclean re
