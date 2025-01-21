CC = c++

CFLAGS = -Wall -Werror -Wextra -std=c++98

DEBUG = -fsanitize=address -g3

LDEBUG = -g

RM = rm -rf

NAME = easy_find

FILES = main \

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
	@if [ "$(shell uname)" = "Linux" ]; then\
		$(CC) $(CFLAGS) $(CFILES) $(LDEBUG) -o $(NAME); \
		echo " \t$(NAME) compiled with debug for linux ✅"; \
	elif [ "$(shell uname)" = "Darwin" ]; then \
		$(CC) $(CFLAGS) $(CFILES) $(DEBUG) -o $(NAME); \
		echo " \t$(NAME) compiled with debug for MacOS ✅"; \
	fi

%.o: %.cpp
	@$(CC) $(CFLAGS) -c $< -o $@
	@printf "\33[2K"

$(NAME): $(CFILES)
	@$(CC) $(CFLAGS) $(CFILES) -o $(NAME)
	@echo " \t$(NAME) compiled ✅"

.PHONY : clean fclean all debug re
