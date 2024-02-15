# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rdragan <rdragan@student.42heilbronn.de    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/01 09:56:13 by rdragan           #+#    #+#              #
#    Updated: 2023/10/18 22:19:15 by rdragan          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	./Polymorphism
SRC		=	main.cpp		\
			Animal.cpp		\
			Cat.cpp			\
			Dog.cpp			\
			Brain.cpp
OBJ		=	main.o			\
			Animal.o		\
			Cat.o			\
			Dog.o			\
			Brain.o
CPPFLAGS	=	-Wall -Werror -Wextra -std=c++98
CC		=	c++

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $^ -o $(NAME)

clean:
	@rm -Rf $(OBJ)

fclean: clean
	@rm -Rf $(NAME)

re: fclean all

.PHONY : clean, fclean, re