# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: angassin <angassin@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/21 17:16:32 by angassin          #+#    #+#              #
#    Updated: 2023/03/09 20:32:18 by angassin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#-------------------------------COLORS------------------------------------------

NONE='\033[0m'
GREEN='\033[32m'
GRAY='\033[2;37m'
CURSIVE='\033[3m'
BLUE='\033[1;94m'
RED='\033[1;91m'

#-------------------------------VARIABLES---------------------------------------

NAME		= so_long

CC			= cc

CFLAGS		= -Wall -Wextra -Werror 

DEBUG		=  -g3 -fsanitize=address

MLX			= -L../mlx -lmlx -framework OpenGL -framework AppKit

#--------------------------------SOURCES----------------------------------------

SRC		= $(GAME_SRC) $(UTILS_SRC)

LIBFT_A 	= libft.a
LIBFT_DIR 	= libft/	
LIBFT		= $(addprefix libft/, $(LIBFT_A))

GAME		= main.c draw.c
GAME_SRC	= $(addprefix src/, $(GAME))

UTILS		= window.c image.c hooks.c read_map.c #color.c
UTILS_SRC	= $(addprefix utils/, $(UTILS)) 

OBJ			= $(SRC:.c=.o)

#---------------------------------RULES-----------------------------------------

%o: %c 
	@$(CC) $(CFLAGS) -Iincludes -c $< -o  $(<:.c=.o)
			
all: $(NAME)

$(NAME): $(OBJ)
	@echo $(CURSIVE)$(GRAY) "     - Making libft..." $(NONE)
	@make -C $(LIBFT_DIR)
	@echo $(CURSIVE)$(GRAY) "     - Compiling $(NAME)..." $(NONE)
	@$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(MLX) -o $(NAME)	
	@echo $(GREEN)"- Compiled -"$(NONE)
	@echo "$(BLUE)								\n\
	 _______  _______       _        _______  _        _______  \n\
	(  ____ \(  ___  )     ( \      (  ___  )( (    /|(  ____ \ \n\
	| (    \/| (   ) |     | (      | (   ) ||  \  ( || (    \/	\n\
	| (_____ | |   | |     | |      | |   | ||   \ | || |      	\n\
	(_____  )| |   | |     | |      | |   | || (\ \) || | ____ 	\n\
	      ) || |   | |     | |      | |   | || | \   || | \_  )	\n\
	/\____) || (___) |     | (____/\| (___) || )  \  || (___) |	\n\
	\_______)(_______)_____(_______/(_______)|/    )_)(_______)	\n\
 	         (_____)             								\n\
															$(Color_Off)"

exe: all
	@make -C ./ clean
	@echo "     - Executing $(NAME)... \n"
	@./$(NAME) maps/42.ber
	@echo "\n     - Done -"

debug: $(OBJ)
	@echo $(CURSIVE)$(GRAY) "     - Making libft..." $(NONE)
	@make -C $(LIBFT_DIR)
	@echo $(CURSIVE)$(GRAY) "     - Compiling $(NAME)..." $(NONE)
	@$(CC) $(CFLAGS) $(DEBUG) $(OBJ) $(LIBFT) $(MLX) -o $(NAME)
	@echo $(GREEN)"- Compiled -"$(NONE) 

clean:
	@echo $(CURSIVE)$(GRAY) "     - Removing object files..." $(NONE)
	@rm -rf $(OBJ)
	@make -C $(LIBFT_DIR) clean

fclean: clean
	@echo $(CURSIVE)$(GRAY) "     - Removing $(NAME)..." $(NONE)
	@rm -rf $(NAME)
	@make -C $(LIBFT_DIR) fclean
	
re: fclean all

.PHONY:	all debug exe clean fclean re bonus 
