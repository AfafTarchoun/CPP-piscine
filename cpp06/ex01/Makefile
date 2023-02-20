NAME = Serialization
SRCS = Serialization.cpp main.cpp 
CC = c++
FLAGS = -Wall -Werror -Wextra -std=c++98

$(NAME) :
	$(CC) $(FLAGS) $(SRCS) -o $(NAME)
	@echo "$(green)source files compiled successfully$(reset)"

all : $(NAME)

fclean :
	rm -f $(NAME)

re: fclean all

.PHONY: all fclean re