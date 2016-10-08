
BIN=bin/
OBJ=obj/
LIB=lib/
SRC=src/
INC=include/
CC=g++


$(BIN)fruteria: $(OBJ)fruteria.o $(LIB)libshop.a
	$(CC) -std=gnu++11 $(OBJ)fruteria.o -o $@ -L$(LIB) -lshop
	###### $@ == objetivo

$(LIB)libshop.a: $(OBJ)producto.o $(OBJ)compra.o
	ar -rsv $(LIB)libshop.a $^
	#####$^ == todas las dependencias.

$(OBJ)fruteria.o: $(SRC)fruteria.cpp $(INC)compra.h $(INC)producto.h
	$(CC) -std=gnu++11 -c $< -o $@ -I$(INC)

$(OBJ)producto.o: $(SRC)producto.cpp $(INC)producto.h
	$(CC) -std=gnu++11 -c $< -o $@ -I$(INC)

$(OBJ)compra.o: $(SRC)compra.cpp $(INC)compra.h $(INC)producto.h
	$(CC) -std=gnu++11 -c $< -o $@ -I$(INC)

clean:
	echo "Limpiando..."
	rm $(OBJ)*.o $LIBlib*.a
