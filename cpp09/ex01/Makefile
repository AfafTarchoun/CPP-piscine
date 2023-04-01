NAME = RPN
SRCS = main.cpp RPN.cpp
CC = c++
FLAGS = -Wall -Werror -Wextra -std=c++98 

$(NAME) :
	$(CC) $(FLAGS) $(SRCS) -o $(NAME)
	@echo "source files compiled successfully"

all : $(NAME)

fclean :
	rm -f $(NAME)

re: fclean all

.PHONY: all fclean re