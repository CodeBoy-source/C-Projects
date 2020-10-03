OBJ=obj
BIN=bin
SRC=src
INC=inc

all: $(BIN)/principal

clean:
	echo "Limpieza archivos objeto..."
	rm $(OBJ)/*.o

mrproper: clean
	rm $(BIN)/principal

$(OBJ)/principal.o:	$(SRC)/principal.cpp $(INC)/utilidades.h
	g++ -c -o $(OBJ)/principal.o -I$(INC) $(SRC)/principal.cpp

$(OBJ)/utilidades.o:	$(SRC)/utilidades.cpp $(INC)/utilidades.h 
	g++ -c -o $(OBJ)/utilidades.o -I$(INC) $(SRC)/utilidades.cpp

$(BIN)/principal:	$(OBJ)/principal.o $(OBJ)/utilidades.o
	g++ -o $(BIN)/principal $(OBJ)/principal.o $(OBJ)/utilidades.o