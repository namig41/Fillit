# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lcarmelo <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/27 15:54:57 by lcarmelo          #+#    #+#              #
#    Updated: 2019/09/27 15:55:04 by lcarmelo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit 

SRC_DIR = ./src/
OBJ_DIR	:= ./obj/
INC_DIR = ./includes/
LIB_DIR = ./libft/

SRC_NAME = main \
			fill_figure \
			take_tetrimino \
			get_next_line \
			solve

LIB_NAME = libft

SRCS = $(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_NAME)))
OBJS = $(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_NAME)))
LIBS = $(addprefix $(LIB_DIR), $(addsuffix .a, $(LIB)))

CC = gcc
CFLAGS = -Wall -Wextra -Werror -I$(INC_DIR) -I$(LIB_DIR) $(LIBS)

all: $(NAME)

obj:
	mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $(SRCS) 

$(NAME): lib obj
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) 

lib:
	make re $(LIB_DIR)

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all
