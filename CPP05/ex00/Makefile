# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rdragan <rdragan@student.42heilbronn.de    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/10 06:44:22 by rdragan           #+#    #+#              #
#    Updated: 2023/11/10 07:32:56 by rdragan          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	exe
SRC		=	main.cpp \
			Bureaucrat.cpp
OBJ		=	$(SRC:.cpp=.o)
CFLAGS	=	-Wall -Werror -Wextra -std=c++98
CC		=	g++

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $^ -o $(NAME)

clean:
	rm -Rf $(OBJ)

fclean: clean
	rm -Rf $(NAME)

re: fclean all