NAME = Harl
SRCS = main.cpp Harl.cpp Harl.hpp 
CC = c++
FLAGS = -Wall -Werror -Wextra

$(NAME) :
	$(CC) $(FLAGS) $(SRCS) -o $(NAME)
	@echo "$(green)source files compiled successfully$(reset)"

all : $(NAME)

fclean :
	rm -f $(NAME)

re: fclean all

.PHONY: all fclean re