CC = c++

CFLAGS = -Wall -Werror -Wextra -std=c++98 -pedantic-errors

DEBUG = -fsanitize=address -g3

RM = rm -rf

NAME = ScalarConverter

SRC_PATH = ./src/

FILES = main \
		$(SRC_PATH)ScalarConverter

CFILES = $(FILES:%=%.cpp)

all : $(NAME)

clean :
	@echo "\n [$(NAME)] - Nettoyage fichier residuels... ♻️ "

fclean : clean
	@echo "\n [$(NAME)] - Supressions du reste... 🗑️"
	@rm -f $(NAME)
	@rm -rf $(NAME).dSYM

re :
	@make fclean
	@make all

debug : $(CFILES)
	@$(CC) $(CFLAGS) $(CFILES) $(DEBUG) -o $(NAME)
	@echo " \t$(NAME) compiled ✅"

%.o: %.cpp
	@$(CC) $(CFLAGS) -c $< -o $@
	@printf "\33[2K"

$(NAME): $(CFILES)
	@$(CC) $(CFLAGS) $(CFILES) -o $(NAME)
	@echo " \t$(NAME) compiled ✅"

.PHONY : clean fclean all debug re
