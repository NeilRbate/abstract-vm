GXX=g++
FLAGS=-std=c++20 -Wall -Wextra -Werror -pedantic
TARGET=abstarct_vm
SRC=src/main.cpp \
	src/FileParse/FileParse.cpp

OBJ=${SRC:.cpp=.o}

.c.o:
	$(GXX) $(FLAGS) -c $< -o $@

$(TARGET): $(OBJ)
	$(GXX) $(FLAGS) -o $@ $^

all: $(OBJ) $(TARGET)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(TARGET)

re: fclean all

.PHONY: all clean fclean re