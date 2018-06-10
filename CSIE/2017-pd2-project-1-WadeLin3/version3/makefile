main: main.o minion.o battle.o
	g++ -o main main.o minion.o battle.o
main.o: main.cpp minion.h battle.h
	g++ -c main.cpp
test: test.o minion.o battle.o
	g++ -o test test.o minion.o battle.o
test.o: test.cpp minion.h battle.h
	g++ -c test.cpp
minion.o: minion.cpp minion.h
	g++ -c minion.cpp
battle.o: battle.cpp minion.h battle.h
	g++ -c battle.cpp
clean:
	rm main *.o
