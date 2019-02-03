# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rkulahin <rkulahin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/26 13:22:53 by rkulahin          #+#    #+#              #
#    Updated: 2019/02/03 14:11:27 by rkulahin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem_in
LIB = libftprintf.a

OBJ_DIR	= ./obj/
SRC_DIR = ./srcs/

SRC = main.c \
read.c
OBJ = $(addprefix $(OBJ_DIR), $(SRC:.c=.o))
INCL = -I includes/
FLAGS =	-g -Wall -Wextra -Werror


all: $(NAME)
$(NAME):	$(OBJ) $(LIB)
	gcc -o $(NAME) $(FLAGS) $(OBJ) $(LIB)

$(OBJ):		| $(OBJ_DIR)

$(OBJ_DIR):
		@mkdir $(OBJ_DIR)

$(OBJ_DIR)%.o:	$(SRC_DIR)%.c
		@gcc -c $< -o $@ $(FLAGS) $(INCL)

$(LIB):
	$(MAKE) all -f ./libftprintf/Makefile
clean :
	@rm -rf $(OBJ_DIR)
	$(MAKE) clean -f ./libftprintf/Makefile
fclean : clean
	@rm -f $(NAME)	
	$(MAKE) fclean -f ./libftprintf/Makefile
re : fclean all
