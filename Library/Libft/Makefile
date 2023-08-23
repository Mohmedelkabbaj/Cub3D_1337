# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hamaarou <hamaarou@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/14 14:48:35 by hamaarou          #+#    #+#              #
#    Updated: 2023/08/23 17:22:59 by hamaarou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=libft.a
CC=cc
CFLAGS=-Wall -Wextra -Werror
SRC= 	ft_isascii.c ft_memcpy.c ft_split.c ft_strlen.c ft_tolower.c \
		ft_isdigit.c ft_memmove.c ft_strchr.c ft_strmapi.c ft_toupper.c \
		ft_atoi.c ft_isprint.c ft_memset.c ft_strdup.c ft_strncmp.c  \
		ft_bzero.c ft_itoa.c ft_putchar_fd.c ft_striteri.c ft_strnstr.c  \
		ft_calloc.c ft_putendl_fd.c ft_strjoin.c ft_strrchr.c  \
		ft_isalnum.c ft_memchr.c ft_putnbr_fd.c  ft_strlcat.c ft_strtrim.c \
		ft_isalpha.c ft_memcmp.c ft_putstr_fd.c  ft_strlcpy.c ft_substr.c ft_isspace.c

OBJ=	ft_isascii.o ft_memcpy.o ft_split.o ft_strlen.o ft_tolower.o \
		ft_isdigit.o ft_memmove.o ft_strchr.o ft_strmapi.o ft_toupper.o \
		ft_atoi.o ft_isprint.o ft_memset.o ft_strdup.o ft_strncmp.o  \
		ft_bzero.o ft_itoa.o ft_putchar_fd.o ft_striteri.o ft_strnstr.o  \
		ft_calloc.o ft_putendl_fd.o ft_strjoin.o ft_strrchr.o  \
		ft_isalnum.o ft_memchr.o ft_putnbr_fd.o  ft_strlcat.o ft_strtrim.o \
		ft_isalpha.o ft_memcmp.o ft_putstr_fd.o  ft_strlcpy.o ft_substr.o ft_isspace.o

all:$(NAME)

.PHONY= all clean fclean re

$(NAME):$(OBJ)
	ar rc $(NAME) $(OBJ)

$(OBJ):$(SRC)
	@ $(CC) $(CFLAGS) -c $(SRC)

clean:
	@ rm -rf $(OBJ)

fclean:clean
	@ rm -rf $(NAME)

re:fclean all
