# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ebouabba <ebouabba@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/19 20:02:37 by ebouabba          #+#    #+#              #
#    Updated: 2022/02/20 12:20:00 by ebouabba         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_FILE =	pipex.c \
			return_path.c \
			check_command.c \
			exceve_cmd.c \
			utils/ft_putchar_fd.c \
			utils/ft_putstr_fd.c \
			utils/ft_strjoin.c \
			utils/ft_strlen.c \
			utils/ft_strncmp.c \
			utils/ft_strnstr.c \
			utils/ft_substr.c \
			utils/ft_split.c 

DOW = \033[1;32m
ROW = \033[1;31m
NAME = pipex
OBJ_FILE = $(SRC_FILE:.c=.o)
CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
HDR = pipex.h

all : $(NAME)

%.o : %.c $(HDR)
	$(CC) $(CFLAGS) -c $< -o $@
	
$(NAME) : $(OBJ_FILE) $(HDR)
	@$(CC) $(CFLAGS) $(OBJ_FILE) -o $(NAME)
	@echo "$(DOW)- - - - -> compiled success"

clean :
	@$(RM) $(OBJ_FILE)
	@echo "$(ROW)- - - - -> object files cleaned"

fclean : clean
		@$(RM) $(OBJ_FILE) $(NAME)
		@echo "$(ROW)- - - - -> cleaned"

re : fclean all

.PHONY: all clean fclean re