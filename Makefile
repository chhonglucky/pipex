# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chanhhon <chanhhon@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/09 17:16:59 by chanhhon          #+#    #+#              #
#    Updated: 2024/05/03 17:13:50 by chanhhon         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=cc
CFLAGS=-Wall -Wextra -Werror
LIBNAME=./$(LIBDIR)/libftprintf.a
LIBDIR=ft_printf
SRCS=main.c csfunc.c csfunc_file.c parseline.c
OBJS=$(SRCS:.c=.o)
NAME=pipex

all: $(NAME)

$(NAME) : $(OBJS) $(LIBNAME)
	$(CC) $(CFLAGS) $(OBJS) $(LIBNAME) -o $(NAME)

$(LIBNAME) :
	$(MAKE) -C $(LIBDIR)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS)
	$(MAKE) -C $(LIBDIR) clean

fclean: clean
	rm -rf $(NAME)
	$(MAKE) -C $(LIBDIR) fclean

re: fclean all

.PHONY: all clean fclean re