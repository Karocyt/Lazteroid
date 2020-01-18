# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: kevazoul <marvin@le-101.fr>                +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2018/08/14 11:09:21 by kevazoul     #+#   ##    ##    #+#        #
#    Updated: 2018/09/05 12:43:38 by kevazoul    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

.PHONY: all clean fclean re so signature

TIME = /usr/bin/time -l # time -v on Ubuntu, time -l on OSX

CC = clang++ -g
CPPFLAGS = -std=c++98 -Wall -Wextra -Werror

SRCDIR = ./
OBJDIR = OBJ/
H_FILES = phonebook.class.hpp contact.class.hpp
INCLUDES = -Iphonebook.class.hpp -Icontact.class.hpp
SRC_NAME =	contact.class.cpp \
			phonebook.class.cpp \
			main.cpp

C_FILES = $(addprefix $(SRCDIR), $(SRC_NAME))
O_FILES = $(patsubst $(SRCDIR)%.cpp, $(OBJDIR)%.o, $(C_FILES)) 
#H_FILE = includes/ft_ssl.h
NAME = phonebook

# **************************************************************************** #
#                                  RULES                                       #
# **************************************************************************** #

all: $(NAME)

$(NAME): $(OBJDIR) $(O_FILES) $(H_FILES) | signature
	$(CC) $(CPPFLAGS) -o $(NAME) $(O_FILES)

$(OBJDIR):
	@mkdir $@

$(OBJDIR)%.o: $(SRCDIR)%.cpp $(H_FILES) | $(OBJDIR)
	@printf %b "0️⃣  $(NAME): Compiling $@ from $<..."
	$(CC) $(CPPFLAGS) -c $(INCLUDES) -o $@ $<
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
	@echo "                    by kevazoul"
	@echo ""

