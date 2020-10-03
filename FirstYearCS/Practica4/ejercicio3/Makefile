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
		rm $(OBJ)/*.o $(LIB)/*a

mrproper: clean
		rm $(BIN)/$(NAME)

$(OBJ)/Valor.o: $(SRC)/Valor.cpp $(INC)/Valor.h
		g++ -c -o $(OBJ)/Valor.o -I$(INC) $(SRC)/Valor.cpp

$(OBJ)/MatrizDispersa.o: $(SRC)/MatrizDispersa.cpp $(INC)/MatrizDispersa.h
		g++ -c -o $(OBJ)/MatrizDispersa.o -I$(INC) $(SRC)/MatrizDispersa.cpp

$(LIB)/$(LIB)formas.a: $(OBJ)/MatrizDispersa.o $(OBJ)/Valor.o
		ar rsv $(LIB)/$(LIB)formas.a $(OBJ)/MatrizDispersa.o $(OBJ)/Valor.o

$(OBJ)/$(NAME).o: $(SRC)/$(NAME).cpp  $(INC)/Valor.h $(INC)/MatrizDispersa.h
		g++ -c -o $(OBJ)/$(NAME).o -I$(INC) $(SRC)/$(NAME).cpp

$(BIN)/$(NAME): $(OBJ)/$(NAME).o 	$(LIB)/$(LIB)formas.a
		g++ -L$(LIB)/ -o $(BIN)/$(NAME) $(OBJ)/$(NAME).o -lformas