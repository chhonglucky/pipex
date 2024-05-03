# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chanhhon <chanhhon@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/09 17:16:59 by chanhhon          #+#    #+#              #
#    Updated: 2023/12/14 17:47:58 by chanhhon         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC_NAME = ./srcs/ft_printf.c \
		   ./srcs/ft_format.c \
		   ./srcs/ft_printf_base.c

SRC = $(SRC_NAME)

OBJS = $(SRC_NAME:.c=.o)

CC = cc

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS)
	@$(MAKE) -C ./Libft
	@cp ./Libft/libft.a $(NAME)
	ar -rcs $(NAME) $(OBJS)
	@ranlib $(NAME)

%.o: $(SRC_PATH)/%.c
	@$(CC) -c $(CFLAGS) -o $@ $< -I includes

clean:
	@$(MAKE) -C ./Libft clean
	@rm -rf $(OBJS)

fclean: clean
	@$(MAKE) -C ./Libft fclean
	@rm -rf $(NAME)

re : fclean all

.PHONY: all clean fclean re