# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fhyman <fhyman@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/04 17:43:01 by fhyman            #+#    #+#              #
#    Updated: 2021/04/11 14:41:12 by fhyman           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		= libft.a

LIB		= libft.h

SRCS 		= ft_strstr.c ft_itoa.c ft_putnbr_fd.c ft_split.c  ft_putendl_fd.c ft_putstr_fd.c ft_putchar_fd.c ft_strmapi.c  ft_strtrim.c ft_strjoin.c ft_substr.c ft_strlcat.c ft_memmove.c ft_calloc.c ft_strnstr.c ft_memchr.c ft_memcmp.c ft_memccpy.c ft_memcpy.c ft_strlcpy.c ft_strdup.c ft_bzero.c ft_strlen.c ft_strrchr.c ft_atoi.c ft_toupper.c ft_tolower.c ft_isprint.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_strncmp.c ft_strchr.c ft_memset.c 

RM	 	= rm -f

AR		= ar rc

CFLAGS 		= -Wall -Wextra -Werror -g

OBJS 		= $(SRCS:.c=.o)

.c.o:
			cc $(CFLAGS) -I$(LIB) -c $< -o $(<:.c=.o)

all: 		$(NAME)

$(NAME):	$(OBJS)
			$(AR) $(NAME) $(OBJS)

clean:
			$(RM) $(OBJS)

fclean: 	clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
