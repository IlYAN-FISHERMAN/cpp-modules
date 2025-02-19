CC = c++
GCC = /opt/homebrew/opt/gcc@14/bin/g++-14

CFLAGS = -Wall -Werror -Wextra -gdwarf-2 -std=c++98

DEBUG = -fsanitize=address -g3 -D DEBUG=1

LDEBUG = -g3

RM = rm -rf

NAME = PmergeMe

FILES = main \
		PmergeMe

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
	
gcc: $(CFILES)
	@$(GCC) $(CFLAGS) $(CFILES) -o $(NAME)
	@echo " \t$(NAME) compiled ✅"

.PHONY : clean fclean all debug re
