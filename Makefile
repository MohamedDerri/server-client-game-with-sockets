
CC = gcc
CFLAGS1 = -Wextra -Wall -Werror -I /usr/local/include -I ./includes
CFLAGS2 = -L src/libft -lft -I ./includes -I /usr/local/include -L /usr/local/lib
NAMEC = client
NAMES = server

SRCS = 	src/server.c 
SRCC = src/client.c


DIRECTORY = objs

all: $(NAMEC) $(NAMES)

$(NAMEC): $(DIRECTORY) 
	@make -C src/libft
	@$(CC) -o $(NAMEC) src/client.c $(CFLAGS1) $(CFLAGS2) src/libft/libft.a
	@echo "\033[0;31m ================================================================================"
	@echo "\033[0;31m|>>>>>>>>>>>>>>>>>>>>\033[0;35m{YOUR CLIENT HAS BEEN COMPILED SUCCESSFULLY}\033[0;31m<<<<<<<<<<<<<<<<<<|"
	@echo "\033[0;31m ================================================================================"
	
$(NAMES): $(DIRECTORY) $(OBJ)
	@$(CC) -o $(NAMES) src/server.c $(CFLAGS1) $(CFLAGS2) src/libft/libft.a
	@echo "\033[0;31m ================================================================================"
	@echo "\033[0;31m|>>>>>>>>>>>>>>>>>>>>\033[0;33m{YOUR SERVER HAS BEEN COMPILED SUCCESSFULLY}\033[0;31m<<<<<<<<<<<<<<<<<<|"
	@echo "\033[0;31m ================================================================================"

$(DIRECTORY):
	@mkdir -p objs

clean:
	@rm -rf objs
	@rm -f $(OBJC)
	@rm -f $(OBJS)
	@make clean -C src/libft
	@echo "\033[0;31m ================================================================================"
	@echo "\033[0;31m|>>>>>>>>>>>>>>>>>>>>>\033[0;32m{YOUR PROJECT HAS BEEN CLEANED SUCCESSFULLY}\033[0;31m<<<<<<<<<<<<<<<<<<|"
	@echo "\033[0;31m ================================================================================"

fclean: clean
	@make fclean -C src/libft
	@rm -f $(NAMEC)
	@rm -f $(NAMES)

re: fclean all
.PHONY: fclean, clean, re, all, server, client
