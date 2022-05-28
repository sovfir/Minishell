# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lshonta <lshonta@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/23 17:12:53 by lshonta           #+#    #+#              #
#    Updated: 2022/05/28 15:45:22 by lshonta          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ./minishell

CFLAGS = -Wall -Wextra -Werror
LFR= -L$$HOME/.brew/opt/readline/lib -lreadline
LFRC = -I$$HOME/.brew/opt/readline/include

SRC_PATH = ./src/
OBJ_PATH = ./obj/

SRC =	$(SRC_PATH)main.c \
		src/executer/*.c	\
		src/utils/*.c	\
		src/parser/*.c	\
		$(SRC_PATH)/env_struct/*c

OBJ = $(patsubst $(SRC_PATH)%.c, $(OBJ_PATH)%.o, $(SRC))

all: $(NAME)

$(OBJ_PATH)%.o :$(SRC_PATH)%.c
	@mkdir -p $(dir $@)
	@gcc $(LFRC) $(CFLAGS) -c -o $@ $<

$(NAME): $(OBJ)
	@gcc $(CFLAGS) $(OBJ) $(LFR) $(LFRC) -o $(NAME)

clean:
	@rm -f -r $(OBJ_PATH);

fclean: clean
	@rm -f $(NAME); 

re: fclean all

norm:
	@norminette | grep Error | egrep --color '.*Error!|$$' || true

.PHONY: all, clean, fclean, re, norm
