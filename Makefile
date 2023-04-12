CC = cc
CFLAGS = -Wall -Wextra -Werror

LIBFT_DIR = lib/libft
CLIENT_DIR = 

all: $(LIBFT_DIR)/libft.a client

client: src/client.c $(LIBFT_DIR)/libft.a
	$(CC) $(CFLAGS) $< -L$(LIBFT_DIR) -lft -o $@

$(LIBFT_DIR)/libft.a:
	$(MAKE) -C $(LIBFT_DIR) all

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	$(RM) client

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re