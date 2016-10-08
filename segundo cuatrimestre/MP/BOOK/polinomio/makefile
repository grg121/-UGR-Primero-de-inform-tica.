#Este makefile esta echo por el profesorado
SRC = src
INC = include
OBJ = obj
BIN = bin
LIB = lib

CXX = g++
CPPFLAGS = -ansi -pedantic -Wall -Wextra -Wwrite-strings -Werror -g -c -std=c++0x -I$(INC)

all: $(BIN)/main

$(BIN)/main: $(OBJ)/main.o $(LIB)/libimagen.a
	$(CXX) $(OBJ)/main.o -limagen -o $(BIN)/main  -L$(LIB)

# ************ Creacion de Objetos ************

$(OBJ)/main.o: $(SRC)/main.cpp $(INC)/polinomio.h
	$(CXX) $(CPPFLAGS) $(SRC)/main.cpp -o $(OBJ)/main.o

$(OBJ)/polinomio.o: $(SRC)/polinomio.cpp $(INC)/polinomio.h
	$(CXX) $(CPPFLAGS) $(SRC)/polinomio.cpp -o $(OBJ)/polinomio.o

# ************ Creacion de bibliotecas ************
$(LIB)/libimagen.a : $(OBJ)/polinomio.o
	ar rvs $(LIB)/libimagen.a $(OBJ)/polinomio.o

# ************ documentación *******

documentacion:
	doxygen doc/doxys/Doxyfile

# ************ Limpieza ************

clean:
	echo "Limpiando..."
	rm $(OBJ)/* $(LIB)/*

mrproper: clean
	rm $(BIN)/* doc/html/*
