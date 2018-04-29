BIN = bin
INC = include
LIB = lib
OBJ = obj
SOL = sol
SRC = src

ARCH = $(shell getconf LONG_BIT)
ifeq ($(ARCH), 32)
  LIBPATH = $(LIB)/lib
else
  LIBPATH = $(LIB)/lib64
endif

XLSFLAGS = -std=c++11 -I $(LIB)/include_cpp -L $(LIBPATH) -lxl -Wl,-rpath,$(LIBPATH)

CXX = g++
CPPFLAGS = -O3 -g -c -std=c++11 -I$(INC)

# ************ Compilacion de los Programas ************

all: $(BIN)/ClasificadorKNN $(BIN)/XLSparser

$(BIN)/XLSparser: $(SRC)/xlsparser.cpp
	$(CXX) -o $(BIN)/XLSparser $(SRC)/xlsparser.cpp $(XLSFLAGS)

$(BIN)/ClasificadorKNN: $(OBJ)/clasificadorknn.o $(OBJ)/clasificador.o $(OBJ)/datos.o $(OBJ)/generador.o $(OBJ)/localsearch.o $(OBJ)/relief.o $(OBJ)/temporizador.o
	$(CXX) $(OBJ)/clasificadorknn.o $(OBJ)/clasificador.o $(OBJ)/datos.o $(OBJ)/generador.o $(OBJ)/localsearch.o $(OBJ)/relief.o $(OBJ)/temporizador.o -o $(BIN)/ClasificadorKNN

# ************ Creacion de Objetos ************

$(OBJ)/clasificador.o: $(SRC)/clasificador.cpp $(INC)/clasificador.h
	$(CXX) $(CPPFLAGS) $(SRC)/clasificador.cpp -o $(OBJ)/clasificador.o

$(OBJ)/clasificadorknn.o: $(SRC)/clasificadorknn.cpp $(INC)/clasificador.h $(INC)/datos.h $(INC)/generador.h $(INC)/localsearch.h $(INC)/relief.h $(INC)/temporizador.h
	$(CXX) $(CPPFLAGS) $(SRC)/clasificadorknn.cpp -o $(OBJ)/clasificadorknn.o

$(OBJ)/datos.o: $(SRC)/datos.cpp $(INC)/datos.h
	$(CXX) $(CPPFLAGS) $(SRC)/datos.cpp -o $(OBJ)/datos.o

$(OBJ)/generador.o: $(SRC)/generador.cpp $(INC)/generador.h
	$(CXX) $(CPPFLAGS) $(SRC)/generador.cpp -o $(OBJ)/generador.o

$(OBJ)/localsearch.o: $(SRC)/localsearch.cpp $(INC)/localsearch.h
	$(CXX) $(CPPFLAGS) $(SRC)/localsearch.cpp -o $(OBJ)/localsearch.o

$(OBJ)/relief.o: $(SRC)/relief.cpp $(INC)/relief.h
	$(CXX) $(CPPFLAGS) $(SRC)/relief.cpp -o $(OBJ)/relief.o

$(OBJ)/temporizador.o: $(SRC)/temporizador.cpp $(INC)/temporizador.h
	$(CXX) $(CPPFLAGS) $(SRC)/temporizador.cpp -o $(OBJ)/temporizador.o

# ************ Limpieza ************

clean:
	$(info "Limpiando...")
	rm -f $(OBJ)/* $(BIN)/* $(SOL)/*.txt
