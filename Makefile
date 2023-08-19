# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hamaarou <hamaarou@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/18 13:13:10 by hamaarou          #+#    #+#              #
#    Updated: 2023/08/19 17:07:44 by hamaarou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=Cub3D
CC=clang
CFLAGS=-Wall -Wextra -Werror 

SRC= cub3d.c 

OBJ=$(SRC:.c=.o)

all: $(NAME)
OBJ = $(SRC:.c=.o)

LIBFT_DIR = ./Library/Libft
GNL_DIR = ./Library/Get_next_line

# Colors for messages
GREEN = \033[0;32m
ORANGE = \033[0;33m
RED= \033[0;31m
NC = \033[0m

all: $(NAME)

$(NAME): $(SRC)
	@ echo "$(GREEN)Building Libft...$(NC)"
	@ make -C $(LIBFT_DIR)
	@ echo "$(GREEN)Building Get_next_line...$(NC)"
	@ make -C $(GNL_DIR)
	@ echo "$(GREEN)Compiling $(NAME)...$(NC)"
	@ $(CC) $(CFLAGS)  $(SRC) $(LIBFT_DIR)/libft.a $(GNL_DIR)/GNL  -o $(NAME) 
	@ echo "$(GREEN)Finished compiling $(NAME) ✅ ✅ $(NC)"

clean:
	@ echo "$(ORANGE)Cleaning object files...$(NC)"
	@ make clean -C $(LIBFT_DIR)
	@ make clean -C $(GNL_DIR)
	@ rm -f $(OBJ)

fclean: clean
	@ echo "$(ORANGE)Cleaning executable...$(NC)"
	@ make fclean -C $(LIBFT_DIR)
	@ make fclean -C $(GNL_DIR)
	@ rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
