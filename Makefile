# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jcaron <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/26 14:57:57 by jcaron            #+#    #+#              #
#    Updated: 2023/01/13 18:33:38 by jcaron           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# files

SRC			=	./src/error.c

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

# for debug
#CFLAG		=	-Weverything

#dependencies library
INC_LIB		=	./libft/
LIBFLAG		=	-L./libft -lft


%.o: %.c
	@$(CC) $(CFLAG) -I$(INC_D) -I$(INC_LIB) -c $< -o $@ 
	@echo "***compilation of '$<' in '$@'***"

all: $(NAME_CLI) $(NAME_SRV)

libft:
	@git submodule update --remote
	@(cd libft && make)
	@echo "***compilation of library libft***"

$(NAME_CLI): libft $(OBJ_CLI)
	@$(CC) $(CFLAG) -I$(INC_D) -I$(INC_LIB) $(OBJ_CLI) -o $(NAME_CLI) $(LIBFLAG)
	@echo "***compilation of client***"

$(NAME_SRV):libft $(OBJ_SRV)
	@$(CC) $(CFLAG) -I$(INC_D) -I$(INC_LIB) $(OBJ_SRV) -o $(NAME_SRV) $(LIBFLAG)
	@echo "***compilation of server***"

clean:
	@rm -f $(OBJ_CLI) $(OBJ_CLI)
	@echo "***delation of all objects files***"

fclean: clean
	@rm -f $(NAME_CLI) $(NAME_SRV)
	@echo "***deletion of binary $(NAME_CLI) and $(NAME_SRV)***"

re: fclean all

.PHONY: all clean fclean re libft
