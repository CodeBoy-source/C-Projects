#ESTO ES UN PROTOTIPO DE MAKEFILE.
NAME=ejercicio6
OBJ=obj
BIN=bin
LIB=lib
SRC=src
INC=include

all: $(BIN)/$(NAME)

clean:
		echo "Limpieza de archivos objetos y bibliotecas..."
		rm $(OBJ)/*.o

mrproper: clean
		rm $(BIN)/$(NAME)

$(OBJ)/Matriz2D.o: $(SRC)/Matriz2D.cpp $(INC)/Matriz2D.h
		g++ -g -c -o $(OBJ)/Matriz2D.o -I$(INC) $(SRC)/Matriz2D.cpp

$(OBJ)/utilidades.o: $(SRC)/utilidades.cpp $(INC)/utilidades.h
		g++ -g -c -o $(OBJ)/utilidades.o -I$(INC) $(SRC)/utilidades.cpp

$(OBJ)/$(NAME).o: $(SRC)/$(NAME).cpp $(INC)/Matriz2D.h
		g++ -g -c -o $(OBJ)/$(NAME).o -I$(INC) $(SRC)/$(NAME).cpp

$(BIN)/$(NAME): $(OBJ)/$(NAME).o 	$(OBJ)/Matriz2D.o $(OBJ)/utilidades.o
		g++ -g -o $(BIN)/$(NAME) $(OBJ)/$(NAME).o $(OBJ)/Matriz2D.o $(OBJ)/utilidades.o