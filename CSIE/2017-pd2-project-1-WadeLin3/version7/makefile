main: main.o minion.o status.o position.o
	g++ -o main main.o minion.o status.o position.o
main.o: main.cpp minion.h status.h position.h
	g++ -c main.cpp
minion.o: minion.cpp minion.h card.h
	g++ -c minion.cpp
status.o: status.cpp status.h card.h
	g++ -c status.cpp
position.o: position.cpp position.h 
	g++ -c position.cpp

player2: player2.o
	g++ -o player2 player2.o
player2.o: player2.cpp
	g++ -c player2.cpp
clean:
	rm main *.o
