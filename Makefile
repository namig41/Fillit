#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aolen <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/03 15:10:57 by aolen             #+#    #+#              #
#    Updated: 2019/09/21 17:32:55 by lcarmelo         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

FUNCS = \
		fillit \
		print_errors \
		get_next_line \
		input_check \
		tetrimino_collection \
		solve
NAME = fillit
SRC = $(addprefix $(SRC_PATH), $(addsuffix .c, $(FUNCS)))
OBJS = $(addsuffix .o, $(FUNCS))
SRC_PATH = ./
INCLUDE_PATH = ./includes/
CFLAGS = -Wall -Wextra -Werror -I$(INCLUDE_PATH)
LIBS = -L./libft -lft
RED = "\033[1;31m"
PURPLE = "\033[1;35m"
GREEN = "\033[1;32m"
NOCOLOR = "\033[0m"

all: $(NAME)

compile:
	@echo $(PURPLE)">>> Compiling..."$(NOCOLOR)

$(OBJS): %.o: $(SRC_PATH)%.c
	gcc -c $(CFLAGS) $^

$(NAME): compile $(OBJS)
	gcc $(CFLAGS) $(LIBS) $(OBJS) -o $(NAME)
	@echo $(GREEN)">>> Succes!"$(NOCOLOR)
clean:
	@echo $(PURPLE)">>> Deleting object files.."$(NOCOLOR)
	rm -f $(OBJS)
fclean: clean
	@echo $(PURPLE)">>> Deleting fillit..."$(NOCOLOR)
	rm -f $(NAME)
	@echo $(GREEN)">>> fillit deleted"$(NOCOLOR)'\n'
re: fclean all
