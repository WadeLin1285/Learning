main: main.o minion.o
	g++ -o main main.o minion.o
main.o: main.cpp minion.h
	g++ -c main.cpp
minion.o: minion.cpp minion.h card.h
	g++ -c minion.cpp

player2: player2.o
	g++ -o player2 player2.o
player2.o: player2.cpp
	g++ -c player2.cpp
clean:
	rm main *.o
