NAME = easy_find
SRCS = main.cpp
CC = c++
FLAGS = -Wall -Werror -Wextra -std=c++98

$(NAME) :
	$(CC) $(FLAGS) $(SRCS) -o $(NAME)
	@echo "source files compiled successfully"

all : $(NAME)

fclean :
	rm -f $(NAME)

clean :
	rm -f $(NAME)

re: fclean clean all

.PHONY: all fclean clean re