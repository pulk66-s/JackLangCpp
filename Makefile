PARSER 		= src/Parser
LLVM		= src/LLVM
AST			= src/AST
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
			$(PARSER)/Ret.cpp \
			$(LLVM)/Context.cpp \
			$(LLVM)/Block.cpp \
			$(LLVM)/IRBuilder.cpp \
			$(LLVM)/Module.cpp \
			$(LLVM)/Type.cpp \
			$(LLVM)/Types/Int.cpp \
			$(LLVM)/Function.cpp \
			$(LLVM)/FunctionType.cpp \
			$(LLVM)/NameGenerator.cpp \
			$(LLVM)/Operation.cpp \
			$(LLVM)/Constant.cpp \
			$(LLVM)/Instruction.cpp \
			$(LLVM)/NamedInstruction.cpp \
			$(LLVM)/Operand.cpp \
			$(LLVM)/Ret.cpp \
			$(AST)/FuncDef.cpp \
			$(AST)/Ret.cpp \
			$(AST)/Line.cpp \
			$(AST)/Num.cpp \
			$(AST)/VarDef.cpp \
			$(AST)/VarName.cpp \
			$(AST)/Binop.cpp \
			$(AST)/FuncCall.cpp \
			$(AST)/Char.cpp

SRC			= src/main.cpp \
			$(SRC_FILES)

CC			= g++
INCLUDES	= -I $(PARSER) -I src/
DEBUG		= -W -Wall -Wextra -g3
LLVM_FLAGS	= -lLLVM-15 -I/usr/include
CPPFLAGS	= $(INCLUDES) $(DEBUG) $(LLVM_FLAGS) -O3

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
	$(CC) -o $(NAME) $(OBJ) $(CPPFLAGS)

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
