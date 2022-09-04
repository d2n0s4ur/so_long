# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jnoh <jnoh@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/26 12:28:52 by jnoh              #+#    #+#              #
#    Updated: 2022/09/04 10:49:12 by jnoh             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		= cc
CFLAGS	= -Wall -Werror -Wextra
SRCS	= 	./srcs/key_event.c ./srcs/main.c \
			./srcs/map_draw.c ./srcs/map_read.c \
			./srcs/map_verify.c ./srcs/utils.c
OBJS	= $(SRCS:.c=.o)
LIBFT	= libft/libft.a
NAME	= so_long
RM 		= rm -f
HEADERS	= ./includes/so_long.h ./libft/libft.h

define libft_call
		cd libft && $(MAKE) $(1) && cd ..
endef

define mlx_call
		cd  mlx && $(MAKE) $(1) && cd ..
endef

$(NAME) : $(OBJS) $(HEADERS)
			$(call libft_call, all)
			$(call mlx_call, all)
			$(CC) -o $(NAME) $(CFLAGS) $(OBJS) -L ./mlx -lmlx -L ./libft -lft -framework OpenGL -framework AppKit

all	: $(NAME)

clean:
	cd libft && make clean && cd ..
	cd mlx && make clean && cd ..
	$(RM) $(OBJS)

fclean:
	cd libft && make fclean && cd ..
	cd mlx && make clean && cd ..
	$(RM) $(OBJS)
	$(RM) $(NAME)

re:
	$(MAKE) fclean
	$(MAKE) all

norm:
	norminette srcs/ includes/ libft/

.PHONY : all clean fclean re