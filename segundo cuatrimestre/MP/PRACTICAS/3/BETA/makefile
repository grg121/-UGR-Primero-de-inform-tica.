
#macros

SRC = src
INC = include
OBJ = obj
BIN = bin
LIB = lib


CXX = g++
CPPFLAGS = -Wall -g -c -I$(INC)

#: $(BIN)/arteASCII
all: $(BIN)/arteASCII $(BIN)/testarteASCII $(BIN)/testplano $(BIN)/testimagen
$(BIN)/testplano: $(OBJ)/testplano.o $(LIB)/libimagen.a
	 g++ $(OBJ)/testplano.o -L$(LIB)/ -limagen  -o  $(BIN)/testplano

$(BIN)/arteASCII: $(OBJ)/arteASCII.o $(LIB)/libimagen.a
	g++ $(OBJ)/arteASCII.o -L$(LIB)/ -limagen  -o  $(BIN)/arteASCII

$(BIN)/testarteASCII: $(OBJ)/testarteASCII.o $(LIB)/libimagen.a
	g++ $(OBJ)/testarteASCII.o -L$(LIB)/ -limagen  -o  $(BIN)/testarteASCII

$(BIN)/testimagen: $(OBJ)/testimagen.o $(LIB)/libimagen.a
	g++ $(OBJ)/testimagen.o -L$(LIB)/ -limagen  -o  $(BIN)/testimagen  # No hace falta poner -llibimagen.a El (-l) hace referencia a lib.a



#ARCHIVOS .o

$(OBJ)/arteASCII.o: $(SRC)/arteASCII.cpp $(INC)/imagen.h
	g++ -c $(SRC)/arteASCII.cpp   -I$(INC)  -o $(OBJ)/arteASCII.o

$(OBJ)/testarteASCII.o: $(SRC)/testarteASCII.cpp $(INC)/imagen.h
	g++ -c $(SRC)/testarteASCII.cpp   -I$(INC)  -o $(OBJ)/testarteASCII.o

$(OBJ)/testplano.o: $(SRC)/testplano.cpp $(INC)/imagen.h
	g++ -c $(SRC)/testplano.cpp   -I$(INC)  -o $(OBJ)/testplano.o

#le ponemos como dependencia /imagen.h, pk ese archivo de be de estar creado pk .cpp lo necesita

$(OBJ)/testimagen.o: $(SRC)/testimagen.cpp $(INC)/imagen.h
	g++ -c $(SRC)/testimagen.cpp   -I$(INC)  -o $(OBJ)/testimagen.o  #importante indicar que busque en la carpeta imagen para el .h

$(LIB)/libimagen.a: $(OBJ)/pgm.o	$(OBJ)/imagen.o $(OBJ)/byte.o
	ar  rsv $(LIB)/libimagen.a  $(OBJ)/pgm.o $(OBJ)/imagen.o $(OBJ)/byte.o  #EN LA CREACION DE LIBRERIA HAY QUE PONER LA SALIDA DESPUES DE RSV Y NO AL FINAL

$(OBJ)/pgm.o: $(SRC)/pgm.cpp  $(INC)/pgm.h
	g++ -c $(SRC)/pgm.cpp  -I$(INC) -o $(OBJ)/pgm.o

$(OBJ)/imagen.o: $(SRC)/imagen.cpp $(INC)/pgm.h $(INC)/imagen.h
	g++ -c $(SRC)/imagen.cpp -I$(INC) -o $(OBJ)/imagen.o

$(OBJ)/byte.o: $(SRC)/byte.cpp $(INC)/byte.h
	g++ -c $(SRC)/byte.cpp -I$(INC) -o $(OBJ)/byte.o



# ************ documentación *******

documentacion:
	doxygen doc/doxys/Doxyfile

# ************ Limpieza ************
