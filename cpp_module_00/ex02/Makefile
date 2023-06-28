# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/28 19:24:52 by cado-car          #+#    #+#              #
#    Updated: 2023/06/28 20:51:22 by cado-car         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/21 15:27:47 by cado-car          #+#    #+#              #
#    Updated: 2023/06/26 18:26:35 by cado-car         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= account

OBJ_PATH	=./obj/

CC			= c++
CFLAGS		= -Wall -Wextra -Werror -std=c++98

RM			= rm -rf

SRC 		= tests.cpp \
			Account.cpp

OBJ 		= $(addprefix $(OBJ_PATH), $(notdir $(SRC:.cpp=.o)))

$(OBJ_PATH)%.o: %.cpp
			@printf "\n$(CY)Generating object...$(RC)\n"
			mkdir -p $(OBJ_PATH)
			$(CC) $(CFLAGS) -c $< -o $@
			@printf "\n$(GR)Object ready!$(RC)\n"

$(NAME): 	$(OBJ)
			@printf "\n$(CY)Generating executable...$(RC)\n"
			$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
			@printf "\n$(GR)Done!$(RC)\n"

all:		$(NAME)

re:			fclean all

clean:
			$(RM) $(OBJ) $(OBJ_PATH)
			@printf "\n$(RE)Objects removed!$(RC)\n\n"

fclean:		clean
			$(RM) $(NAME) test_output.log
			@printf "\n$(RE)Executables removed!$(RC)\n\n"

test:		all
			@printf "\n$(YE)Running tests...$(RC)\n"
			@./run_test.sh; \
			if [ $$? -eq 0 ]; then \
				printf "\n$(GR)Test Passed\n\n$(RC)"; \
			else \
				printf "\n$(RE)Test Failed\n\n$(RC)"; \
			fi

# Colors
CY			= \033[36;1m
YE			= \033[33;1m
GR			= \033[32;1m
RE			= \033[31;1m
RC			= \033[0m
