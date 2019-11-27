# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: euan <ehollidg@student.codam.nl>             +#+                      #
#                                                    +#+                       #
#    Created: 2019/04/04 15:51:09 by euan           #+#    #+#                 #
#    Updated: 2019/06/11 11:12:50 by ehollidg      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

SRC = main drawinfo hookcontrols readfile closeprogram fdfloop plotpoint \
    	inbounds bcolour isoproject drawmap convertfile resetmap \
		drawline rowtoarray fisoproject parallelproject normalproject \
		switchpos setrotmatrix rotate validate colourconvert changeprojection
SRCF = $(SRC:%=srcs/%.c)
OBJ = $(SRC:%=%.o)
NAME = fdf
MINILIBX = -I minilibx -L minilibx -lmlx -framework OpenGL -framework Appkit
LIBFT = -I libft/includes -L libft -lft
FLAGS = -Wall -Werror -Wextra

COLOURMAKE = \033[38;5;69m
COLOURCLEAN = \033[38;5;159m
COLOURFCLEAN = \033[38;5;117m
COlOURLIB = \033[38;5;111m
COLOURRESET = \033[0m

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(SRCF)
	@echo "$(COlOURLIB)Compiling Libaries$(COLOURRESET)"
	@make -C libft/
	@make -C minilibx/
	@echo "$(COLOURMAKE)Compiling Program$(COLOURRESET)"
	@clang $(FLAGS) -I minilibx -I libft/includes -c $(SRCF)
	@clang -o $(NAME) $(OBJ) $(LIBFT) $(MINILIBX)

clean:
	@echo "$(COLOURCLEAN)Cleaning Libaries$(COLOURRESET)"
	@make -C libft/ clean
	@make -C minilibx/ clean
	@rm -f $(OBJ)

fclean: clean
	@echo "$(COLOURFCLEAN)Removing Libaries and $(NAME) $(COLOURRESET)"
	@make -C libft/ fclean
	@rm -f $(NAME)

re: fclean all
