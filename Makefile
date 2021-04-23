# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fhyman <fhyman@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/03 20:03:59 by fhyman            #+#    #+#              #
#    Updated: 2021/04/21 21:37:40 by fhyman           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

LIB = libft/libft.a minilibx/libmlx.a

HEAD = *.h

INPUT = $(wildcard *.c)

FLAGS = -framework AppKit -framework OpenGL 

CFLAGS = -Wall -Wextra -Werror -g

RM	 	= rm -f

AR		= ar rc

OBJS 		= $(INPUT:.c=.o)

.c.o:
		cc $(CFLAGS) -c $< -o $(<:.c=.o)

 all: $(NAME) 

$(NAME):	$(OBJS)
	$(MAKE) -C ./libft
	gcc $(OBJS) $(LIB) ${FLAGS} -o $(NAME)

clean:	
			$(MAKE) clean -C ./libft
			$(RM) $(OBJS)

fclean: 	clean
			$(MAKE) fclean -C ./libft
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
