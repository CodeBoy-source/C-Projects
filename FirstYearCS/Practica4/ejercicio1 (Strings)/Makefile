#ESTO ES UN PROTOTIPO DE MAKEFILE.
NAME=ejercicio1
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

$(OBJ)/BigInt.o: $(SRC)/BigInt.cpp $(INC)/BigInt.h
		g++ -c -o $(OBJ)/BigInt.o -I$(INC) $(SRC)/BigInt.cpp

$(OBJ)/$(NAME).o: $(SRC)/$(NAME).cpp $(INC)/BigInt.h
		g++ -c -o $(OBJ)/$(NAME).o -I$(INC) $(SRC)/$(NAME).cpp

$(BIN)/$(NAME): $(OBJ)/$(NAME).o $(OBJ)/BigInt.o
		g++ -o $(BIN)/$(NAME) $(OBJ)/$(NAME).o $(OBJ)/BigInt.o