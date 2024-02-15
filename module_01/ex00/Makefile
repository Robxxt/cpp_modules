# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rdragan <rdragan@student.42heilbronn.de    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/01 11:29:20 by rdragan           #+#    #+#              #
#    Updated: 2023/10/06 14:55:26 by rdragan          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	Brainz
SRC		=	main.cpp \
			Zombie.cpp \
			newZombie.cpp \
			randomChump.cpp
OBJ		=	main.o \
			Zombie.o \
			newZombie.o \
			randomChump.o
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