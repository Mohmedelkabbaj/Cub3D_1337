# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hamaarou <hamaarou@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/18 13:13:10 by hamaarou          #+#    #+#              #
#    Updated: 2023/10/21 11:09:51 by hamaarou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=Cub3D
CC = cc
CFLAGS = -Wall -Wextra -Werror #-g3 -fsanitize=address
FRAMWORK = -L/usr/local/lib -lmlx -framework OpenGL -framework AppKit -lm
PATH = -I/usr/local/include

LIBFT_DIR = ./Library/Libft
GNL_DIR = ./Library/Get_next_line

SRC = cub3d.c \
      Parsing/read_map.c \
      Parsing/config/config_is_set.c \
      Parsing/player/num_of_player.c \
      Parsing/player/position.c \
      Parsing/directions/cardinal_directions.c \
      Parsing/directions/parsing_textures.c \
      Parsing/floor_ceiling/rgb_parse.c \
      Parsing/floor_ceiling/checks.c \
      Parsing/floor_ceiling/rgb.c \
      Parsing/floor_ceiling/rgb_is_set.c \
      Parsing/free/free_array.c \
      Parsing/free/free_textures.c \
      Parsing/free/free_rgb.c \
      Parsing/free/free_all.c \
      Parsing/init_struct/init.c \
      Parsing/map/dimension.c \
      Parsing/map/map_is_last.c \
      Parsing/map/is_map_closed.c \
      Parsing/map/rectangle.c \
      Parsing/map/map_lines.c \
      Parsing/map/map_check.c\
      RayCasting/player_calcule.c \
      RayCasting/mapmini.c
      
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
