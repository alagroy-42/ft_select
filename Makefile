# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alagroy- <alagroy-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/24 09:41:35 by alagroy-          #+#    #+#              #
#    Updated: 2019/04/24 13:50:52 by alagroy-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_select

SRCS = main.c tools.c core.c lst_tools.c

OBJ = $(SRCS:.c=.o)

CC = gcc

INCLUDES = includes

CFLAGS = -Wall -Werror -Wextra -I $(INCLUDES)

DFLAGS = -Wall -Werror -Wextra -g3 -fsanitize=address -I $(INCLUDES)

%.o: %.c
	@printf "\033[0;32m[ft_select] Compilation [.o]\r"
	@$(CC) $(CFLAGS) -c $< -o $@
	@printf "\033[0;32m[ft_select] Compilation [.o]\r"

all: $(NAME)

debug:
	$(CC) $(DFLAGS) libft/*.c -ltermcap $(SRCS) -o $(NAME)

$(NAME): $(OBJ)
	@printf "\033[0;32m[ft_select] Compilation [OK]\n"
	@make -C libft
	@mv libft/libft.a .
	@printf "\033[0;32m[ft_select] Linking [.o]\r"
	@$(CC) $(CFLAGS) -L . -ltermcap -lft $(OBJ) -o $(NAME)
	@printf "\033[0;32m[ft_select] Linking [OK]\n"

clean:
	@make -C libft clean
	@rm -f $(OBJ)
	@printf "\033[0;31m[ft_select] Clean [OK]\n"

fclean: clean
	@rm -f $(NAME)
	@rm -f libft.a
	@printf "\033[0;31m[ft_select] Fclean [OK]\n"

re: fclean all

.PHONY: fclean clean all re debug