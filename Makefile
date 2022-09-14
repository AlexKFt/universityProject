all: factory

factory: factory.o  CompressorStation.o Pipe.o menu.o
	g++ factory.o CompressorStation.o Pipe.o menu.o -o factory

factory.o: factory.cpp
	g++ -c factory.cpp

CompressorStation.o: CompressorStation.cpp
	g++ -c CompressorStation.cpp

Pipe.o: Pipe.cpp
	g++ -c Pipe.cpp

menu.o: menu.cpp
	g++ -c menu.cpp

clean:
	rm -rf *.o factory
