CXX=clang++
NAME = ft_gkrellm
FLAGS =  -Wall -Wextra -Werror -I include
OBJDIR = obj/
SRCDIR = src/
_SRC =	ncWindow.cpp \
		main.cpp \
		Exceptions.cpp \
		SysInfo.cpp \

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
