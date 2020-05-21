CC = g++
OBJFLAGS = -w -c
INC = -Iheaders
LIB = -L/usr/lib

all: maiorSequencia

maiorSequencia: lib/main.o lib/collatz.o
	$(CC) $(INC) $(LIB) $^ -o $@

lib/main.o: src/main.cpp
	$(CC) $(INC) $(LIB) $^ $(OBJFLAGS) -o $@

lib/collatz.o: src/collatz.cpp
	$(CC) $(INC) $(LIB) $^ $(OBJFLAGS) -o $@

clean:
	rm -rf lib/*.o maiorSequencia
