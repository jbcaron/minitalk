# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jcaron <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/26 14:57:57 by jcaron            #+#    #+#              #
#    Updated: 2023/01/11 14:09:27 by jcaron           ###   ########.fr        #
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
CFLAG		=	-Weverything

# for debug
#CFLAG		=	-Weverything

%.o: %.c $(INC_D)*.h Makefile
	@$(CC) $(CFLAG) -I$(INC_D) -c $< -o $@
	@echo "***compilation of '$<' in '$@'***"

all: $(NAME_CLI) $(NAME_SRV)

libft.a:
	@(cd libft && make)
	@cp ./libft/libft.a ./
	@cp ./libft/libft.h $(INC_D)
	@echo "***compilation of library libft***"

$(NAME_CLI): libft.a $(OBJ_CLI)
	@$(CC) $(CFLAG) -I$(INC_D) $(OBJ_CLI) -o $(NAME_CLI) libft.a
	@echo "***compilation of client***"

$(NAME_SRV):libft.a $(OBJ_SRV)
	@$(CC) $(CFLAG) -I$(INC_D) $(OBJ_SRV) -o $(NAME_SRV) libft.a
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
