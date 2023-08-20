# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hamaarou <hamaarou@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/18 16:41:44 by hamaarou          #+#    #+#              #
#    Updated: 2023/08/18 17:13:30 by hamaarou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=GNL
CC=cc
CFLAGS=-Wall -Wextra -Werror
SRC=get_next_line.c \
	get_next_line_utils.c
OBJ=$(SRC:.c=.o)

# $(NAME): $(OBJ)
# 	@ $(CC) $(CFLAGS) -o $(NAME)   $(OBJ)

all: $(NAME)

$(NAME):$(OBJ)
	ar rc $(NAME) $(OBJ)
	
clean:
	@ rm -f $(OBJ)

fclean: clean
	@ rm -f $(NAME)

re: fclean all