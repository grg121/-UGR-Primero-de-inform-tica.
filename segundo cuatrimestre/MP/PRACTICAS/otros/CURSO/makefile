
BIN=bin/
OBJ=obj/
LIB=lib/
SRC=src/
INC=include/
CC=g++

all: $(BIN)proyecto

$(BIN)proyecto: $(OBJ)proyecto.o $(LIB)libcurso.a
	$(CC) -o $@ $< -lcurso -L$(LIB) -I$(INC)

$(LIB)libcurso.a: $(OBJ)alumno.o $(OBJ)examen.o
	ar -rsv $(LIB)libcurso.a $(OBJ)alumno.o $(OBJ)examen.o

$(OBJ)proyecto.o: $(SRC)main.cpp $(INC)alumno.h $(INC)examen.h
	$(CC) -c $(SRC)main.cpp -o $@ -I$(INC)

$(OBJ)alumno.o: $(SRC)alumno.cpp $(INC)alumno.h $(INC)examen.h
	$(CC) -c $< -o $@ -I$(INC)

$(OBJ)examen.o: $(SRC)examen.cpp $(INC)examen.h
	$(CC) -c $< -o $@ -I$(INC)



clean:
	echo "LIMPIANDO..."
	rm obj/*.o lib/lib*.a
