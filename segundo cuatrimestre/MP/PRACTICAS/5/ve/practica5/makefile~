
#macros
BIN=bin/
OBJ=obj/
INC=include/
LIB=lib/
SRC=src/

CXX = g++
CPPFLAGS = -Wall -g -c -I$(INC)

#: $(BIN)arteASCII
all: $(BIN)arteASCII $(BIN)arteASCII2 $(BIN)testarteASCII $(BIN)testplano $(BIN)testimagen

$(BIN)testplano: $(OBJ)testplano.o $(LIB)libimagen.a
	 g++ $(OBJ)testplano.o -L$(LIB) -limagen  -o  $(BIN)testplano

$(BIN)arteASCII: $(OBJ)arteASCII.o $(LIB)libimagen.a
	g++ $(OBJ)arteASCII.o -L$(LIB) -limagen  -o  $(BIN)arteASCII

$(BIN)arteASCII2: $(OBJ)arteASCII2.o $(LIB)libimagen.a
		g++ $(OBJ)arteASCII2.o -L$(LIB) -limagen  -o  $(BIN)arteASCII2

$(BIN)testarteASCII: $(OBJ)testarteASCII.o $(LIB)libimagen.a
	g++ $(OBJ)testarteASCII.o -L$(LIB) -limagen  -o  $(BIN)testarteASCII

$(BIN)testimagen: $(OBJ)testimagen.o $(LIB)libimagen.a
	g++ $(OBJ)testimagen.o -L$(LIB) -limagen  -o  $(BIN)testimagen  # No hace falta poner -llibimagen.a El (-l) hace referencia a lib.a



#ARCHIVOS .o

$(OBJ)arteASCII.o: $(SRC)arteASCII.cpp $(INC)imagen.h
	g++ -c $(SRC)arteASCII.cpp   -Iinclude  -o $(OBJ)arteASCII.o

$(OBJ)arteASCII2.o: $(SRC)arteASCII2.cpp $(INC)imagen.h $(INC)lista.h
	g++ -c $(SRC)arteASCII2.cpp   -Iinclude  -o $(OBJ)arteASCII2.o

$(OBJ)testarteASCII.o: $(SRC)testarteASCII.cpp $(INC)imagen.h
	g++ -c $(SRC)testarteASCII.cpp   -Iinclude  -o $(OBJ)testarteASCII.o

$(OBJ)testplano.o: $(SRC)testplano.cpp $(INC)imagen.h
	g++ -c $(SRC)testplano.cpp   -Iinclude  -o $(OBJ)testplano.o

#le ponemos como dependencia imagen.h, pk ese archivo de be de estar creado pk .cpp lo necesita

$(OBJ)testimagen.o: $(SRC)testimagen.cpp $(INC)imagen.h
	g++ -c $(SRC)testimagen.cpp   -Iinclude  -o $(OBJ)testimagen.o  #importante indicar que busque en la carpeta imagen para el .h

$(LIB)libimagen.a: $(OBJ)pgm.o	$(OBJ)imagen.o $(OBJ)byte.o $(OBJ)lista.o
	ar  rsv    $(LIB)libimagen.a  $(OBJ)pgm.o $(OBJ)lista.o $(OBJ)imagen.o $(OBJ)byte.o

$(OBJ)pgm.o: $(SRC)pgm.cpp  $(INC)pgm.h
	g++ -c $(SRC)pgm.cpp  -Iinclude -o $(OBJ)pgm.o

$(OBJ)imagen.o: $(SRC)imagen.cpp $(INC)pgm.h $(INC)imagen.h $(INC)lista.h
	g++ -c $(SRC)imagen.cpp -Iinclude -o $(OBJ)imagen.o

$(OBJ)byte.o: $(SRC)byte.cpp $(INC)byte.h
	g++ -c $(SRC)byte.cpp -Iinclude -o $(OBJ)byte.o

$(OBJ)lista.o: $(SRC)lista.cpp $(INC)lista.h
	g++ -c $(SRC)lista.cpp -Iinclude -o $(OBJ)lista.o

# ************ documentación *******

documentacion:
	doxygen doc/doxys/Doxyfile

# ************ Limpieza ************

clean:
	echo "Limpiando..."
	rmdir $(OBJ)*.o $(LIB)lib*.a $(bin)*
