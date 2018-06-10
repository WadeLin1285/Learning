main: main.o Elo.o
	g++ -o main main.o Elo.o
main.o: main.cpp Elo.h
	g++ -c main.cpp
Elo.o: Elo.cpp Elo.h
	g++ -c Elo.cpp
clean:
	rm main *.o
