tetris5: tetris5.o genMino.o Mino.o MinoL.o MinoS.o MinoI.o MinoT.o MinoO.o
	g++ -o tetris5 tetris5.o genMino.o Mino.o MinoL.o MinoS.o MinoI.o MinoT.o MinoO.o
tetris5.o: tetris5.cpp genMino.h
	g++ -c tetris5.cpp
Mino.o: Mino.cpp Mino.h
	g++ -c Mino.cpp
MinoL.o: MinoL.cpp MinoL.h
	g++ -c MinoL.cpp
MinoS.o: MinoS.cpp MinoS.h
	g++ -c MinoS.cpp
MinoI.o: MinoI.cpp MinoI.h
	g++ -c MinoI.cpp
MinoT.o: MinoT.cpp MinoT.h
	g++ -c MinoT.cpp
MinoO.o: MinoO.cpp MinoO.h
	g++ -c MinoO.cpp
genMino.o: genMino.cpp genMino.h
	g++ -c genMino.cpp 
clean:
	rm tetris5 *.o
