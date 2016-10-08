
BIN=bin/
OBJ=obj/
LIB=lib/
SRC=src/
INC=includes/
CC=g++

all: $(BIN)proyecto

$(BIN)proyecto: $(OBJ)proyecto.o $(LIB)libcurso.a $(OBJ)head.o
	$(CC) -o $@ $< -lcurso -L$(LIB) -I$(INC) $(OBJ)head.o

$(LIB)libcurso.a: $(OBJ)alumno.o $(OBJ)examen.o $(OBJ)curso.o
	ar -rsv $(LIB)libcurso.a $(OBJ)alumno.o $(OBJ)examen.o $(OBJ)curso.o

$(OBJ)curso.o: $(SRC)curso.cpp $(INC)curso.h $(INC)examen.h $(INC)head.h
	$(CC) -c $< -o $@ -I$(INC) 

$(OBJ)proyecto.o: $(SRC)main.cpp $(INC)alumno.h $(INC)examen.h $(INC)head.h
	$(CC) -c $(SRC)main.cpp -o $@ -I$(INC)

$(OBJ)alumno.o: $(SRC)alumno.cpp $(INC)alumno.h $(INC)examen.h $(INC)head.h
	$(CC) -c $< -o $@ -I$(INC)

$(OBJ)examen.o: $(SRC)examen.cpp $(INC)examen.h $(INC)head.h
	$(CC) -c $< -o $@ -I$(INC)

$(OBJ)head.o: $(SRC)head.cpp $(INC)head.h
	$(CC) -c $< -o $@ -I$(INC)



clean:
	echo "LIMPIANDO..."
	rm obj/*.o lib/lib*.a
