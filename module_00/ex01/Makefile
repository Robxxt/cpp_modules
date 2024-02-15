# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rdragan <rdragan@student.42heilbronn.de    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/01 11:29:20 by rdragan           #+#    #+#              #
#    Updated: 2023/10/05 12:54:24 by rdragan          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	PhoneBookApp
SRC		=	main.cpp \
			PhoneBook.class.cpp \
			Contact.class.cpp \
			utils.cpp \
			App.class.cpp
OBJ		=	main.o \
			PhoneBook.class.o \
			Contact.class.o \
			utils.o \
			App.class.o
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