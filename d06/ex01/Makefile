UNAME := $(shell uname)

ifeq ($(UNAME), Linux)
CXX=g++
else
CXX=clang++
endif

NAME = serialize

#FLAGS =  -Wall -Wextra `pkg-config --cflags --libs ncurses` -std=c++98 # add -Werror

FLAGS =  -Wall -Wextra -Werror

OBJDIR = obj/

SRCDIR = src/

_SRC =	main.cpp \

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
