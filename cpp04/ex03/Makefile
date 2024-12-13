CC = c++

CFLAGS = -Wall -Werror -Wextra -std=c++98

DEBUG= -fsanitize=address -g3
 
RM = rm -rf

NAME = inter_recap

FILE_PATH = ./src/

FILES = main \
		$(FILE_PATH)Dog \
		$(FILE_PATH)Cat \
		$(FILE_PATH)Animal \
		$(FILE_PATH)WrongCat \
		$(FILE_PATH)WrongAnimal \
		$(FILE_PATH)Brain \
		$(FILE_PATH)AMateria \
		$(FILE_PATH)Ice \
		$(FILE_PATH)Cure \
		$(FILE_PATH)Character

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
	@$(CC) $(CFLAGS) $(CFILES) -g3 -fsanitize=address -o $(NAME)
	@echo " \t$(NAME) compiled ✅"

bary : $(CFILES)
	@$(CC) $(CFLAGS) $(CFILES) -D FUNCT=1 -o $(NAME)
	@echo " \t$(NAME) compiled ✅"

%.o: %.cpp
	@$(CC) $(CFLAGS) -c $< -o $@
	@printf "\33[2K"

$(NAME): $(CFILES)
	@$(CC) $(CFLAGS) $(CFILES) -o $(NAME)
	@echo " \t$(NAME) compiled ✅"

.PHONY : clean fclean all debug re
