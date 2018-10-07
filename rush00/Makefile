CXX=clang++

NAME = ft_retro

#FLAGS =  -Wall -Wextra `pkg-config --cflags --libs ncurses` -std=c++98 # add -Werror

FLAGS =  -Wall -Wextra -Werror

OBJDIR = objects/

SRCDIR = sources/

_SRC =	Boss.cpp \
		Enemy.cpp \
		Game.cpp \
		HPObject.cpp \
		main.cpp \
		node_t.cpp \
		Object.cpp \
		Player.cpp \
		Star.cpp \
		Bullet.cpp \

SRC = $(addprefix $(SRCDIR), $(_SRC))

OBJ = $(addprefix $(OBJDIR),$(_SRC:.cpp=.o))

all: make_dir $(NAME)

make_dir:
	mkdir -p $(OBJDIR)

$(OBJDIR)%.o: $(SRCDIR)%.cpp
	$(CXX) $(FLAGS) -o $@ -c $<

$(NAME): $(OBJ) $(SRC)
	$(CXX) $(FLAGS) -lncurses -o $(NAME) $(OBJ)

clean:
	rm -rf $(OBJDIR)

fclean: clean
	rm -rf $(NAME)

re: fclean all
