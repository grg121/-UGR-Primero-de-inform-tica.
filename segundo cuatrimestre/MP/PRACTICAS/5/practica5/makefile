
#macros
BIN=bin/
OBJ=obj/
INC=include/
LIB=lib/
SRC=src/

CXX = g++ 
CPPFLAGS = -Wall -g -c --std=c++11 -I$(INC)

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
#con el CPPFLAGS remplazo el -c y -Iinclude 
$(OBJ)arteASCII.o: $(SRC)arteASCII.cpp 
	g++ $(CPPFLAGS) $(SRC)arteASCII.cpp     -o $(OBJ)arteASCII.o

$(OBJ)arteASCII2.o: $(SRC)arteASCII2.cpp $(INC)imagen.h $(INC)lista.h
	g++ $(CPPFLAGS) $(SRC)arteASCII2.cpp     -o $(OBJ)arteASCII2.o

$(OBJ)testarteASCII.o: $(SRC)testarteASCII.cpp $(INC)imagen.h
	g++ $(CPPFLAGS) $(SRC)testarteASCII.cpp     -o $(OBJ)testarteASCII.o

$(OBJ)testplano.o: $(SRC)testplano.cpp $(INC)imagen.h
	g++ $(CPPFLAGS) $(SRC)testplano.cpp     -o $(OBJ)testplano.o

#le ponemos como dependencia imagen.h, pk ese archivo de be de estar creado pk .cpp lo necesita

$(OBJ)testimagen.o: $(SRC)testimagen.cpp $(INC)imagen.h
	g++ $(CPPFLAGS) $(SRC)testimagen.cpp   -Iinclude  -o $(OBJ)testimagen.o  #importante indicar que busque en la carpeta imagen para el .h

$(LIB)libimagen.a: $(OBJ)pgm.o	$(OBJ)imagen.o $(OBJ)byte.o $(OBJ)lista.o
	ar  rsv    $(LIB)libimagen.a  $(OBJ)pgm.o $(OBJ)lista.o $(OBJ)imagen.o $(OBJ)byte.o

$(OBJ)pgm.o: $(SRC)pgm.cpp  $(INC)pgm.h
	g++ $(CPPFLAGS) $(SRC)pgm.cpp   -o $(OBJ)pgm.o

$(OBJ)imagen.o: $(SRC)imagen.cpp $(INC)pgm.h $(INC)imagen.h $(INC)lista.h
	g++ $(CPPFLAGS) $(SRC)imagen.cpp  -o $(OBJ)imagen.o

$(OBJ)byte.o: $(SRC)byte.cpp $(INC)byte.h
	g++ -c $(SRC)byte.cpp -Iinclude -o $(OBJ)byte.o

$(OBJ)lista.o: $(SRC)lista.cpp $(INC)lista.h
	g++ $(CPPFLAGS) $(SRC)lista.cpp  -o $(OBJ)lista.o

# ************ documentación *******

documentacion:
	doxygen doc/doxys/Doxyfile

# ************ Limpieza ************

mrproper: clean
	@rm  bin/* 	#con las macros elimina bien pero da un error(puede ser por la ((/)) implementada en la macro)
clean:
	@echo "Limpiando..." #el  @ no me muetra echo "Limpiando" y luego limpiando
	@rm lib/lib*.a obj/*.o
