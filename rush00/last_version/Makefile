# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: apelykh <apelykh@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/07 23:17:13 by apelykh           #+#    #+#              #
#    Updated: 2018/10/07 23:33:05 by apelykh          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CXX=clang++
NAME = ft_retro
FLAGS =  -Wall -Wextra -Werror -I include
OBJDIR = obj/
SRCDIR = src/
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
		Exceptions.cpp \

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
