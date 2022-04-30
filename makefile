FLAGS = -Wall -pedantic -Wextra -O3
MV = -mv *.o bin/
MD = -mkdir bin/
DEL = -rm -r bin/*.o bin/ pop
CCC = cc -c
CCO = cc -o

all: pop

.PHONY: all clean

pop: main.o pop.o memory.o prints.o
	$(CCO) $@ $^
	$(MD)
	$(MV)

main.o: src/main.c src/memory.h src/pop.h
	$(CCC) $< $(FLAGS)

memory.o: src/memory.c src/memory.h
	$(CCC) $< $(FLAGS)

pop.o: src/pop.c src/pop.h
	$(CCC) $< $(FLAGS)

prints.o: src/prints.c src/prints.h
	$(CCC) $< $(FLAGS)

clean:
	$(DEL)
