SRC = main.cpp

NAME = ft_containers

CC = c++

FLAGS = -Wall -Wextra -Werror -std=c++98 -g

OBJ = $(SRC:.cpp=.o)

$(NAME): $(OBJ)
	$(CC) $(FLAGS) -o $(NAME) $(SRC)

%.o: %.cpp
	$(CC) $(FLAGS) -c $<

all: $(NAME)

clean:
	rm -rf $(OBJ)

fclean:
	rm -rf $(NAME) $(OBJ)

re: fclean all