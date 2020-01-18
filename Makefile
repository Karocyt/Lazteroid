# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: mmoya <mmoya@student.le-101.fr>            +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2018/08/14 11:09:21 by kevazoul     #+#   ##    ##    #+#        #
#    Updated: 2020/01/18 17:50:12 by mmoya       ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

.PHONY: all clean fclean re so signature

TIME = /usr/bin/time -l # time -v on Ubuntu, time -l on OSX

CC = clang++
CPPFLAGS = -std=c++98 -Wall -Wextra -Werror -g

SRCDIR = src/
OBJDIR = obj/
H_FILES_NAMES = Constants.hpp \
				Point.hpp \
				Unit.hpp \
				Enemy.hpp \
				Projectile.hpp \
				Player.hpp \
				Game.hpp
INCLUDES_DIR = includes/
INCLUDES = $(addprefix -I, $(INCLUDES_DIR))
H_FILES = $(addprefix $(INCLUDES_DIR), $(H_FILES_NAMES))
SRC_NAME =	Point.cpp \
			Unit.cpp \
			Enemy.cpp \
			Projectile.cpp \
			Player.cpp \
			Game.cpp \
			main.cpp

C_FILES = $(addprefix $(SRCDIR), $(SRC_NAME))
O_FILES = $(patsubst $(SRCDIR)%.cpp, $(OBJDIR)%.o, $(C_FILES)) 
#H_FILE = includes/ft_ssl.h
NAME = Laz-steroïd

# **************************************************************************** #
#                                  RULES                                       #
# **************************************************************************** #

all: $(NAME)

$(NAME): $(OBJDIR) $(O_FILES) $(H_FILES) | signature
	$(CC) $(CPPFLAGS) -lncurses -o $(NAME) $(INCLUDES) $(O_FILES)

$(OBJDIR):
	@mkdir $@

$(OBJDIR)%.o: $(SRCDIR)%.cpp $(H_FILES) | $(OBJDIR)
	@printf %b "0️⃣  $(NAME): Compiling $@ from $<..."
	$(CC) $(CPPFLAGS) $(INCLUDES) -c -o $@ $<
	@printf "\r" && printf "                                                                                             \r"


clean:
	@printf "[X] $(NAME): Deleting objects and temporary files... "
	@rm -rf $(OBJDIR)
	@printf "[V]\n"

fclean: clean
	@printf "[X] $(NAME): Deleting $(NAME)... "
	@rm -f $(NAME)
	@printf "[V]\n"

re: fclean all

signature:
	@echo "   ,ad8888ba,                           "
	@echo " d8\"\'    \`\"8b      aa          aa      "
	@echo "d8\'                88          88      "
	@echo "88             aaaa88aaaa  aaaa88aaaa  "
	@echo "88             \"\"\"\"88\"\"\"\"  \"\"\"\"88\"\"\"\"  "
	@echo "Y8,                88          88      "
	@echo " Y8a.    .a8P      \"\"          \"\"      "
	@echo "  \`\"Y8888Y\"\'                           "
	@echo "                 ©2020 moya & kevazoul"
	@echo ""

