# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/21 15:27:47 by cado-car          #+#    #+#              #
#    Updated: 2023/08/30 21:16:42 by cado-car         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= Identify

OBJ_PATH	=./obj/

CC			= c++
CFLAGS		= -Wall -Wextra -Werror -std=c++98 -Wshadow

RM			= rm -rf

SRC 		= main.cpp \
			Base.cpp \
			identify.cpp
			

OBJ 		= $(addprefix $(OBJ_PATH), $(notdir $(SRC:.cpp=.o)))

$(OBJ_PATH)%.o: %.cpp
			@printf "\n$(CY)Generating object...$(RC)\n"
			mkdir -p $(OBJ_PATH)
			$(CC) $(CFLAGS) -c $< -o $@
			@printf "\n$(GR)Object ready!$(RC)\n"

$(NAME): 	$(OBJ)
			@printf "\n$(CY)Generating executable...$(RC)\n"
			$(CC) $(CFLAGS) $(OBJ) -I $(OBJ_PATH) -o $(NAME)
			@printf "\n$(GR)Done!$(RC)\n"

all:		$(NAME)

re:			fclean all

clean:
			$(RM) $(OBJ) $(OBJ_PATH)
			@printf "\n$(RE)Objects removed!$(RC)\n\n"

fclean:		clean
			$(RM) $(NAME)
			@printf "\n$(RE)Executables removed!$(RC)\n\n"

leak:		all
			valgrind --leak-check=full --track-origins=yes ./${NAME}

# Colors
CY			= \033[36;1m
YE			= \033[33;1m
GR			= \033[32;1m
RE			= \033[31;1m
RC			= \033[0m
