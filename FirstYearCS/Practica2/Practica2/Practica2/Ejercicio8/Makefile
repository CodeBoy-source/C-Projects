OBJ=obj
BIN=bin
SRC=src
INC=include

all: $(BIN)/principal

clean:
	echo "Limpieza archivos objeto y biblioteca..."
	rm $(OBJ)/*.o $(LIB)/*.a

mrproper: clean
	rm $(BIN)/principal


$(OBJ)/EstimadorDistancia.o:$(SRC)/EstimadorDistancia.cpp $(INC)/EstimadorDistancia.h
	g++ -c -o $(OBJ)/EstimadorDistancia.o -I$(INC) $(SRC)/EstimadorDistancia.cpp

$(OBJ)/principal.o: $(SRC)/principal.cpp $(INC)/EstimadorDistancia.h
	g++ -c -o $(OBJ)/principal.o -I$(INC) $(SRC)/principal.cpp

$(BIN)/principal: $(OBJ)/principal.o $(OBJ)/EstimadorDistancia.o
	g++ -o $(BIN)/principal $(OBJ)/principal.o $(OBJ)/EstimadorDistancia.o
