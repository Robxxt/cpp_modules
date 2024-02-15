# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rdragan <rdragan@student.42heilbronn.de    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/12 22:48:14 by rdragan           #+#    #+#              #
#    Updated: 2023/10/17 01:00:40 by rdragan          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	FragTrap
SRC		=	main.cpp \
			ClapTrap.cpp \
			FragTrap.cpp
OBJ		=	main.o \
			ClapTrap.o \
			FragTrap.o
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