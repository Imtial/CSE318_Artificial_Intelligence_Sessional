CC = g++
FLAGS = -c -g

puzzle: Node.o Heuristic.o MinHeap.o AStar.o Main.o
	$(CC) -o puzzle *.o

Heuristic.o: Heuristic.h Heuristic.cpp
	$(CC) $(FLAGS) Heuristic.cpp

Node.o: Node.h Node.cpp
	$(CC) $(FLAGS) Node.cpp

MinHeap.o: MinHeap.h MinHeap.cpp
	$(CC) $(FLAGS) MinHeap.cpp

AStar.o: AStar.h AStar.cpp
	$(CC) $(FLAGS) AStar.cpp

Main.o: Main.cpp
	$(CC) $(FLAGS) Main.cpp

run: 
	./puzzle
clean:
	rm *.o puzzle