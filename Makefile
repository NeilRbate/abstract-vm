GXX=g++
CXXFLAGS=-std=c++20 -Wall -Wextra -Werror -pedantic
TARGET=abstarct_vm
SRC=src/main.cpp \
	src/FileParse/FileParse.cpp \
	src/Operand/OperandFactory.cpp \
	src/Operand/Operand.cpp \
	src/Lexer/Lexer.cpp \
	src/Execute/Execute.cpp \
	src/UserInput/UserInput.cpp

OBJ=${SRC:.cpp=.o}


.c.o:
	${GXX} ${CXXFLAGS} -c $< -o ${<:.c=.o}

${TARGET}: ${OBJ}
	${GXX} ${CXXFLAGS} -o ${TARGET} ${OBJ}

all: ${OBJ} ${TARGET}


clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(TARGET)

re: fclean all

.PHONY: all clean fclean re
