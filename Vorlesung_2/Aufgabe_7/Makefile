
NAME	:= Aufgabe7

SRCS	:= Aufgabe_7.cpp

CC		:= g++

OBJS	:=

CFLAGS	:= -Wall -Werror -Wextra

$(NAME): $(SRCS)
	$(CC) $(CFLAGS) $^ -o $@

.PHONY: all re clean fclean

all: $(NAME)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all
