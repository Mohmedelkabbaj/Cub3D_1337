# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mel-kabb <mel-kabb@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/18 13:13:10 by hamaarou          #+#    #+#              #
#    Updated: 2023/11/04 16:27:42 by mel-kabb         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=Cub3D
CC = cc
CFLAGS = -Wall -Wextra -Werror -g3 -fsanitize=address
FRAMWORK = -L/usr/local/lib -lmlx -framework OpenGL -framework AppKit -lm
PATH = -I/usr/local/include

LIBFT_DIR = ./Library/Libft
GNL_DIR = ./Library/Get_next_line


SRC =	cub3d.c $(wildcard ./Parsing/*.c) $(wildcard ./Parsing/config/*.c) $(wildcard ./Parsing/player/*.c) \
		$(wildcard ./Parsing/directions/*.c) $(wildcard ./Parsing/direction/*.c) \
		$(wildcard ./Parsing/floor_ceiling/*.c) $(wildcard ./Parsing/free/*.c) \
		$(wildcard ./Parsing/init_struct/*.c) $(wildcard ./Parsing/map/*.c) \
		$(wildcard ./RayCasting/line/*.c) $(wildcard ./RayCasting/hooks/*.c) $(wildcard ./RayCasting/utils/*.c) \
		$(wildcard ./Raycasting/ray/*.c) $(wildcard ./mlx/*.c) $(wildcard ./RayCasting/3Dwalls/*.c) \

     
OBJ = $(SRC:.c=.o)


GREEN = \033[0;32m
ORANGE = \033[0;33m
RED = \033[0;31m
NC = \033[0m

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(PATH) $(SRC) $(LIBFT_DIR)/libft.a $(GNL_DIR)/GNL $(FRAMWORK) -o $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

# Phony Targets (Not Dependent on Files)
.PHONY: all clean fclean re
