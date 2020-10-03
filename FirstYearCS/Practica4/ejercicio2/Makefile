#ESTO ES UN PROTOTIPO DE MAKEFILE.
NAME=ejercicio2
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

$(OBJ)/Punto.o: $(SRC)/Punto.cpp $(INC)/Punto.h
		g++ -c -o $(OBJ)/Punto.o -I$(INC) $(SRC)/Punto.cpp

$(OBJ)/Polilinea.o: $(SRC)/Polilinea.cpp $(INC)/Polilinea.h
		g++ -c -o $(OBJ)/Polilinea.o -I$(INC) $(SRC)/Polilinea.cpp

$(LIB)/$(LIB)formas.a: $(OBJ)/Punto.o $(OBJ)/Polilinea.o
		ar rsv $(LIB)/$(LIB)formas.a $(OBJ)/Punto.o $(OBJ)/Polilinea.o

$(OBJ)/$(NAME).o: $(SRC)/$(NAME).cpp  $(INC)/Polilinea.h $(INC)/Punto.h
		g++ -c -o $(OBJ)/$(NAME).o -I$(INC) $(SRC)/$(NAME).cpp

$(BIN)/$(NAME): $(OBJ)/$(NAME).o 	$(LIB)/$(LIB)formas.a
		g++ -L$(LIB)/ -o $(BIN)/$(NAME) $(OBJ)/$(NAME).o -lformas