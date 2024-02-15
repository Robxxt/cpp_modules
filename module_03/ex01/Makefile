# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rdragan <rdragan@student.42heilbronn.de    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/12 22:48:14 by rdragan           #+#    #+#              #
#    Updated: 2023/10/16 22:49:29 by rdragan          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	ScavTrap
SRC		=	main.cpp \
			ClapTrap.cpp \
			ScavTrap.cpp
OBJ		=	main.o \
			ClapTrap.o \
			ScavTrap.o
CFLAGS	=	-Wall -Werror -Wextra -std=c++98
CC		=	c++

all: $(NAME)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $^ -o $(NAME)

clean:
	@rm -Rf $(OBJ)

fclean: clean
	@rm -Rf $(NAME)

re: fclean all

.PHONY : clean, fclean, re