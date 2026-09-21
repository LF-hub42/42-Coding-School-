# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ekypraio <ekypraio@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/05 15:32:32 by ekypraio          #+#    #+#              #
#    Updated: 2025/11/10 18:12:05 by ekypraio         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
SRC = ft_printf.c ft_putnbr_x.c ft_putchar_fd.c ft_putnbr_x.c ft_putnbr.c ft_putptr.c ft_putstr_fd.c ft_strchr.c ft_strlen.c
OBJ = $(SRC:.c=.o)

CFLAGS = -Wall -Wextra -Werror
CC = cc
AR = ar rcs
RM = rm -f

all: $(NAME)

$(NAME): $(OBJ)
	$(AR) $(NAME) $(OBJ)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
