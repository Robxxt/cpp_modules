# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rdragan <rdragan@student.42heilbronn.de    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/06 15:22:33 by rdragan           #+#    #+#              #
#    Updated: 2023/10/09 00:51:04 by rdragan          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	Harl
SRC		=	main.cpp \
			Harl.cpp
OBJ		=	main.o \
			Harl.o
CFLAGS	=	-Wall -Werror -Wextra -std=c++98 -pedantic
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