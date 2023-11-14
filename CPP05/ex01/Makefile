# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rdragan <rdragan@student.42heilbronn.de    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/10 06:44:22 by rdragan           #+#    #+#              #
#    Updated: 2023/11/14 09:30:55 by rdragan          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	exe
SRC		=	main.cpp \
			Bureaucrat.cpp \
			Form.cpp
			
OBJ		=	$(SRC:.cpp=.o)
CFLAGS	=	-Wall -Werror -Wextra -std=c++98
CC		=	c++

%.o:%.cpp
	$(CC) $(CFLAGS) -c $^ -o $@

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $^ -o $(NAME)

clean:
	rm -Rf $(OBJ)

fclean: clean
	rm -Rf $(NAME)

re: fclean all