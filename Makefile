# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chermist <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/21 15:27:21 by chermist          #+#    #+#              #
#    Updated: 2019/01/21 23:44:00 by chermist         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= fillit

FNAMES = main.c
FNAMES +=	check_validity.c \
			save_fig.c fillit.c
LIB_DIR	= ./libft

SRC	= $(addprefix srcs/, $(FNAMES))

# compiler and flags
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror
LIB_FLAGS	= -L./libft -lft

.PHONY: all clean fclean re

all:	$(NAME)


$(NAME):
	@$(MAKE) -C $(LIB_DIR)
	@$(CC) $(CFLAGS) $(SRC) $(LIB_FLAGS) -o $(NAME)

clean:
	@rm -rf	$(LIB_DIR)/*.o

fclean: clean
	@rm -rf $(LIB_DIR)/*.a
	@rm -rf $(NAME)

re:
	@$(MAKE) fclean
	@$(MAKE) all

relibs:
	@$(MAKE) -C $(LIB_DIR) re
	@$(MAKE) re