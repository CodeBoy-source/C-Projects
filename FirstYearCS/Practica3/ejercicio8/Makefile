#ESTO ES UN PROTOTIPO DE MAKEFILE.
NAME=ejercicio8ç
OBJ=obj
BIN=bin
LIB=lib
SRC=src
INC=include

all: $(BIN)/$(NAME)

clean:
		echo "Limpieza de archivos objetos y bibliotecas..."
		rm $(OBJ)/*.o $(LIB)/*a

mrproper: clean
		rm $(BIN)/$(NAME)

$(OBJ)/Node.o: $(SRC)/Node.cpp $(INC)/Node.h
		g++ -c -o $(OBJ)/Node.o -I$(INC) $(SRC)/Node.cpp

$(OBJ)/List.o: $(SRC)/List.cpp $(INC)/List.h
		g++ -c -o $(OBJ)/List.o -I$(INC) $(SRC)/List.cpp

$(LIB)/$(LIB)formas.a: $(OBJ)/Node.o $(OBJ)/List.o
		ar rsv $(LIB)/$(LIB)formas.a $(OBJ)/Node.o $(OBJ)/List.o

$(OBJ)/$(NAME).o: $(SRC)/$(NAME).cpp  $(INC)/Node.h $(INC)/List.h
		g++ -c -o $(OBJ)/$(NAME).o -I$(INC) $(SRC)/$(NAME).cpp

$(BIN)/$(NAME): $(OBJ)/$(NAME).o 	$(LIB)/$(LIB)formas.a
		g++ -L$(LIB)/ -o $(BIN)/$(NAME) $(OBJ)/$(NAME).o -lformas