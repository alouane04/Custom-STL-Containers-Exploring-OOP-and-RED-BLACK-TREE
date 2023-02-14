SRC = main.cpp vector_test.cpp map_test.cpp set_test.cpp

NAME = ft_containers

CC = c++

FLAGS = -Wall -Wextra -Werror -std=c++98

OBJ = $(SRC:.cpp=.o)

$(NAME): common.hpp $(OBJ)
	$(CC) $(FLAGS) -o $(NAME) $(SRC)

%.o: %.cpp
	$(CC) $(FLAGS) -c $<

all: $(NAME)

clean:
	rm -rf $(OBJ)

fclean:
	rm -rf $(NAME) $(OBJ)

re: fclean all