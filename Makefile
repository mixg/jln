# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mxiong <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/22 17:36:34 by mxiong            #+#    #+#              #
#    Updated: 2018/04/15 21:12:19 by mxiong           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRCS = remove.c \
         main.c \
         solve.c \
         extra_function.c \
         map.c \
         read_open.c \
         patterns.c \
		 remove_newline.c

LIB = libft/libft.a

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(LIB):
	@make -C libft

$(NAME): $(LIB) $(OBJS)
	@gcc -Wall -Wextra -Werror $(OBJS) $(LIB) -o $(NAME)

%.o: %.c
	@gcc -Wall -Werror -Wextra -c $^

clean:
	@rm -f $(OBJS)
	@make -C libft clean

fclean: clean
	@rm -f $(NAME)
	@make -C libft fclean

re: fclean all
