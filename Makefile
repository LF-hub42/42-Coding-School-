# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ekypraio <ekypraio@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/17 14:24:46 by ekypraio          #+#    #+#              #
#    Updated: 2025/10/28 17:30:43 by ekypraio         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


# // TODO
# Here is the recipe to create your libary

# Normal compilation;
# cc file.c -Wall -Wextra -Werror

# For libary;
# cc -Wall -Wextra -Werror -c file1.c file2.c -o file1.o file2.o
# ar -rc libft.a file1.o file2.o

NAME := libft.a

CC := cc
CFLAGS := -Wall -Wextra -Werror

AR := ar
ARFLAGS := rc

# ar =archiv
# rc = fuegt in archiv ein oder erstellt eins falls nicht vorhanden

S_FILES	:=	ft_toupper.c ft_isalpha.c ft_isdigit.c ft_tolower.c ft_isalnum.c ft_strmapi.c \
ft_isascii.c ft_strchr.c ft_isprint.c ft_strrchr.c ft_strlen.c ft_putendl_fd.c \
ft_strncmp.c ft_memset.c ft_bzero.c ft_memchr.c ft_memcpy.c ft_memcmp.c ft_strtrim.c \
ft_memmove.c ft_strnstr.c ft_strlcpy.c ft_strlcat.c ft_atoi.c ft_putstr_fd.c ft_putchar_fd.c\
ft_strdup.c ft_calloc.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_itoa.c ft_putnbr_fd.c ft_striteri.c\

#  ft_split.c \


O_FILES = $(S_FILES:.c=.o)
BOBJ := $(B_FILES:%.c=%.o)
OFILES = $(CFILES:.c=.o)

.PHONY: all clean fclean re bonus bonuslib

all: $(NAME)

$(NAME) : $(O_FILES)
	$(AR) $(ARFLAGS) $(NAME) $(OBJ)

#%.o: %.c
# 	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(O_FILES) $(BOBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all






