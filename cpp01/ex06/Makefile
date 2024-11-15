CC = c++

CFLAGS = -Wall -Werror -Wextra -std=c++98

RM = rm -rf

NAME = harlFilter

FILES = main \
		Harl

CFILES = $(FILES:%=%.cpp)

all : $(NAME)

clean :
	@echo "\n [$(NAME)] - Nettoyage fichier residuels... ♻️ "

fclean : clean
	@echo "\n [$(NAME)] - Supressions du reste... 🗑️"
	@rm -f $(NAME)

re :
	@make fclean
	@make all

debug : $(CFILES)
	@$(CC) $(CFLAGS) $(CFILES) -g3 -fsanitize=address -o $(NAME)
	@echo " \t$(NAME) compiled ✅"

%.o: %.cpp
	@$(CC) $(CFLAGS) -c $< -o $@
	@printf "\33[2K"

$(NAME): $(CFILES)
	@$(CC) $(CFLAGS) $(CFILES) -o $(NAME)
	@echo " \t$(NAME) compiled ✅"

.PHONY : clean fclean all debug re
