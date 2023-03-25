PARSER 		= src/Parser
SRC			= src/main.cpp \
			src/File.cpp \
			$(PARSER)/Parser.cpp \
			$(PARSER)/Expr.cpp \
			$(PARSER)/Token.cpp \
			$(PARSER)/Num.cpp \
			$(PARSER)/Var.cpp \
			$(PARSER)/Binop.cpp \

CC			= g++
INCLUDES	= -I $(PARSER) -I src/
DEBUG		= -W -Wall -Wextra -g3
CPPFLAGS	= $(INCLUDES) $(DEBUG) -O3

OBJ			= $(SRC:.cpp=.o)
NAME		= jacklang

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(OBJ)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all
