# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jcaron <jcaron@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/26 14:57:57 by jcaron            #+#    #+#              #
#    Updated: 2023/10/08 18:16:03 by jcaron           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# files

SRC			=	./src/error.c \
				./src/str_is.c \
				./dynamic_string/dyn_str.c

INC_D		=	./include/

SRC_CLI		:=	$(SRC) ./src/msg_cli.c ./src/client.c
SRC_SRV		:=	$(SRC) ./src/msg_srv.c ./src/server.c

OBJ_CLI		=	$(SRC_CLI:%.c=%.o)
OBJ_SRV		=	$(SRC_SRV:%.c=%.o)

NAME_CLI	=	client
NAME_SRV	=	server


# compilation
CC			=	clang
CFLAG		=	-Wall -Werror -Wextra


%.o: %.c
	@$(CC) $(CFLAG) -I$(INC_D) -c $< -o $@ 
	@echo "***compilation of '$<' in '$@'***"

all: $(NAME_CLI) $(NAME_SRV)

$(NAME_CLI): $(OBJ_CLI)
	@$(CC) $(CFLAG) -I$(INC_D) $(OBJ_CLI) -o $(NAME_CLI)
	@echo "***compilation of client***"

$(NAME_SRV): $(OBJ_SRV)
	@$(CC) $(CFLAG) -I$(INC_D)  $(OBJ_SRV) -o $(NAME_SRV)
	@echo "***compilation of server***"

clean:
	@rm -f $(OBJ_CLI) $(OBJ_SRV)
	@echo "***delation of all objects files***"

fclean: clean
	@rm -f $(NAME_CLI) $(NAME_SRV)
	@echo "***deletion of binary $(NAME_CLI) and $(NAME_SRV)***"

re: fclean all

.PHONY: all clean fclean re libft
