NAME= a.out
CXX = c++
CPPFLAGS= -std=c++98 #-Wall -Wextra -Werror
SRC= main.cpp Bureaucrat.cpp
OBJ= $(SRC:.cpp=.o)

all: $(NAME)

$(NAME):$(OBJ)
	$(CXX) $(CPPFLAGS) $(OBJ) -o $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re