#ESTO ES UN PROTOTIPO DE MAKEFILE.
NAME=ejercicio4
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

$(OBJ)/Rep.o: $(SRC)/Rep.cpp $(INC)/Rep.h
		g++ -c -o $(OBJ)/Rep.o -I$(INC) $(SRC)/Rep.cpp

$(OBJ)/Sequence.o: $(SRC)/Sequence.cpp $(INC)/Sequence.h
		g++ -c -o $(OBJ)/Sequence.o -I$(INC) $(SRC)/Sequence.cpp

$(LIB)/$(LIB)formas.a: $(OBJ)/Sequence.o $(OBJ)/Rep.o
		ar rsv $(LIB)/$(LIB)formas.a $(OBJ)/Sequence.o $(OBJ)/Rep.o

$(OBJ)/$(NAME).o: $(SRC)/$(NAME).cpp  $(INC)/Rep.h $(INC)/Sequence.h
		g++ -c -o $(OBJ)/$(NAME).o -I$(INC) $(SRC)/$(NAME).cpp

$(BIN)/$(NAME): $(OBJ)/$(NAME).o 	$(LIB)/$(LIB)formas.a
		g++ -L$(LIB)/ -o $(BIN)/$(NAME) $(OBJ)/$(NAME).o -lformas