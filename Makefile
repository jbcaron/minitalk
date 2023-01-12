# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jcaron <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/26 14:57:57 by jcaron            #+#    #+#              #
#    Updated: 2023/01/12 20:10:37 by jcaron           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# files

SRC			=	./src/error.c

INC_D		=	./include/

SRC_CLI		:=	$(SRC) ./src/msg_cli.c ./src/client.c
SRC_SRV		:=	$(SRC) ./src/msg_srv.c ./src/server.c

OBJ_CLI		=	$(SRC_CLI:%.c=%.o)
OBJ_SRV		=	$(SRC_SRV:%.c=%.o)

# compilation

NAME_CLI	=	client
NAME_SRV	=	server

CC			=	clang
CFLAG		=	-Wall -Werror -Wextra
LIBFLAG		=	-I./libft -L./libft -lft

# for debug
#CFLAG		=	-Weverything

%.o: %.c $(INC_D)*.h Makefile
	@$(CC) $(CFLAG) -I$(INC_D) -I./libft -c $< -o $@ 
	@echo "***compilation of '$<' in '$@'***"

all: $(NAME_CLI) $(NAME_SRV)

libft.a:
	@git submodule update --init
	@(cd libft && make)
	@echo "***compilation of library libft***"

$(NAME_CLI): libft.a $(OBJ_CLI)
	@$(CC) $(CFLAG) -I$(INC_D)  $(OBJ_CLI) -o $(NAME_CLI) $(LIBFLAG)
	@echo "***compilation of client***"

$(NAME_SRV):libft.a $(OBJ_SRV)
	@$(CC) $(CFLAG) -I$(INC_D) $(OBJ_SRV) -o $(NAME_SRV) $(LIBFLAG)
	@echo "***compilation of server***"

clean:
	@(cd libft && make clean)
	@rm -f $(OBJ_CLI) $(OBJ_CLI)
	@echo "***delation of all objects files***"

fclean: clean
	@(cd libft && make fclean)
	@rm -f $(NAME_CLI) $(NAME_SRV)
	@echo "***deletion of binary $(NAME_CLI) and $(NAME_SRV)***"

re: fclean all

.PHONY: all clean fclean re debug
