PARSER 		= src/Parser
SRC_FILES	= src/File.cpp \
			$(PARSER)/Parser.cpp \
			$(PARSER)/Expr.cpp \
			$(PARSER)/Token.cpp \
			$(PARSER)/Num.cpp \
			$(PARSER)/FuncDef.cpp \
			$(PARSER)/VarName.cpp \
			$(PARSER)/VarDef.cpp \
			$(PARSER)/Binop.cpp \
			$(PARSER)/Space.cpp \
			$(PARSER)/Char.cpp \
			$(PARSER)/Many.cpp \
			$(PARSER)/Line.cpp \
			$(PARSER)/FuncCall.cpp \
			$(PARSER)/Either.cpp \

SRC			= src/main.cpp \
			$(SRC_FILES)

CC			= g++
INCLUDES	= -I $(PARSER) -I src/
DEBUG		= -W -Wall -Wextra -g3
CPPFLAGS	= $(INCLUDES) $(DEBUG) -O3

UTESTS		= tests/unit
TESTS_SRC	= $(SRC_FILES) \
			$(UTESTS)/num.cpp \
			$(UTESTS)/var.cpp \
			$(UTESTS)/eq.cpp \
			$(UTESTS)/binop.cpp \

TEST_NAME	= jl_unit_tests
TEST_FLAGS	= -lcriterion --coverage $(CPPFLAGS)

OBJ			= $(SRC:.cpp=.o)
NAME		= jacklang

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(OBJ)

clean:
	$(RM) *.gcda
	$(RM) *.gcno
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

unit_tests: $(TEST_NAME)

coverage: unit_tests
	gcovr --exclude tests

$(TEST_NAME): fclean
	$(CC) $(TESTS_SRC) -o $(TEST_NAME) $(TEST_FLAGS)
	./$(TEST_NAME)

re: fclean all
