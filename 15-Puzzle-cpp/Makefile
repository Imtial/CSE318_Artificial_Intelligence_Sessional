CC = g++
FLAGS = -c -g
OBJS = Heuristic.o Node.o MinHeap.o AStar.o Main.o

puzzle: Node.o Heuristic.o MinHeap.o AStar.o Main.o
	$(CC) -o puzzle $(OBJS)

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

Tester.o: Tester.cpp
	$(CC) $(FLAGS) Tester.cpp

tester: Heuristic.o MinHeap.o Node.o Tester.o
	$(CC) -o tester Heuristic.o MinHeap.o Node.o Tester.o

test:
	./tester

run: 
	./puzzle
clean:
	rm *.o puzzle