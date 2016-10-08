
BIN=bin
OBJ=obj
LIB=lib/
SRC=src
INC=include/

bin/central: obj/central.o lib/libformas.a
	g++ -o $(BIN)/central $(OBJ)/central.o -L$(LIB) -lformas

lib/libformas.a: $(OBJ)/punto.o $(OBJ)/circulo.o
	ar -rsv $(LIB)libformas.a $(OBJ)/punto.o $(OBJ)/circulo.o

obj/central.o: $(SRC)/central.cpp
	g++ -c $(SRC)/central.cpp -o $(OBJ)/central.o  -I$(INC)

obj/punto.o: $(SRC)/punto.cpp include/punto.h
	g++ -c $(SRC)/punto.cpp -o $(OBJ)/punto.o -I$(INC)

obj/circulo.o: $(SRC)/circulo.cpp $(INC)/circulo.h $(INC)/punto.h
	g++ -c $(SRC)/circulo.cpp -o $(OBJ)/circulo.o -I$(INC)

clean:
	echo "LIMPIANDO..."
	rm obj/*.o lib/lib*.a
