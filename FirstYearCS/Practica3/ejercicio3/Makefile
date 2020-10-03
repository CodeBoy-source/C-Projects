#ESTO ES UN PROTOTIPO DE MAKEFILE.
NAME=ejercicio3
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

$(OBJ)/utilidades.o: $(SRC)/utilidades.cpp $(INC)/utilidades.h
		g++ -c -o $(OBJ)/utilidades.o -I$(INC) $(SRC)/utilidades.cpp

$(OBJ)/$(NAME).o: $(SRC)/$(NAME).cpp $(INC)/utilidades.h
		g++ -c -o $(OBJ)/$(NAME).o -I$(INC) $(SRC)/$(NAME).cpp

$(BIN)/$(NAME): $(OBJ)/$(NAME).o $(OBJ)/utilidades.o
		g++ -o $(BIN)/$(NAME) $(OBJ)/$(NAME).o $(OBJ)/utilidades.o