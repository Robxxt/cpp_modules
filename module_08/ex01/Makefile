# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rdragan <rdragan@student.42heilbronn.de    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/07 10:42:35 by rdragan           #+#    #+#              #
#    Updated: 2023/12/27 11:43:38 by rdragan          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	exe
SRC		=	main.cpp \
			Span.cpp
OBJ		=	$(SRC:.cpp=.o)
CFLAGS	=	-Wall -Werror -Wextra -std=c++98
INCLUDE	=	-I .
CC		=	c++

%.o:%.cpp
	$(CC) $(CFLAGS) $(INCLUDE) -c $^ -o $@

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $^ -o $(NAME)

clean:
	rm -Rf $(OBJ)

fclean: clean
	rm -Rf $(NAME)

re: fclean all