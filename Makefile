# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mchingi <mchingi@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/22 00:06:28 by mchingi           #+#    #+#              #
#    Updated: 2025/04/02 18:12:54 by mchingi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

CC = @cc
CFLAGS = -Wall -Wextra -Werror
TFLAGS = -pthread
RM = @rm -f

SRCS = ./src/main.c ./src/parsing.c   

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
		$(CC) $(CFLAGS) $(TFLAGS) $(OBJS) -o $(NAME)
		@echo "Completed!"
clean:
		$(RM) $(OBJS)
		@echo "$(OBJS) deleted!"

fclean: clean
		$(RM) $(NAME)
		@echo Program deleted!

re: fclean all