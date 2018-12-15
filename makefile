CC = g++ -std=c++11

all: AAL_Tomasz_Wiaderek.o graph.o
	$(CC) AAL_Tomasz_Wiaderek.o graph.o -o program

AAL_Tomasz_Wiaderek.o: AAL_Tomasz_Wiaderek.cpp Graph.h
	$(CC) AAL_Tomasz_Wiaderek.cpp -c -o AAL_Tomasz_Wiaderek.o

graph.o: Graph.cpp Graph.h
	$(CC) Graph.cpp -c -o graph.o

clean:
	rm -f *.o program
