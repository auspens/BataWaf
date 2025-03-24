NAME = exec

CC = c++

CFLAGS = -Wall -Wextra -Werror -std=c++17

OBJ_DIR = obj

SRC = 	src/Card.cpp \
		src/Deck.cpp \
		src/Game.cpp \
		src/Player.cpp \
		src/main.cpp \

OBJ = $(SRC:src/%.cpp=$(OBJ_DIR)/%.o)

HDR = includes/Card.hpp \
		includes/Deck.hpp \
		includes/Game.hpp \
		includes/Player.hpp

all: $(NAME)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

$(OBJ_DIR)/%.o: src/%.cpp $(HDR) | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re