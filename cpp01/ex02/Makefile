NAME = Brain
SRCS = main.cpp
CC = c++
FLAGS = -Wall -Werror -Wextra

$(NAME) :
	$(CC) $(FLAGS) $(SRCS) -o $(NAME)
	@echo "$(green)source files compiled successfully$(reset)"

all : $(NAME)

fclean :
	rm -f $(NAME)

clean :
	rm -f $(NAME)

re: fclean clean all

.PHONY: all fclean clean re