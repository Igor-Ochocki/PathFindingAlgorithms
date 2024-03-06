dfs: prerequisites
	cc dfs.c data_reader.o maze_structure.o -o dfs
	rm -rf *.o
	./dfs

bfs: prerequisites
	cc bfs.c data_reader.o maze_structure.o -o bfs
	rm -rf *.o
	./bfs

random: prerequisites
	cc random.c data_reader.o maze_structure.o -o random
	rm -rf *.o
	./random

astar: prerequisites
	cc -ggdb astar.c data_reader.o maze_structure.o -o astar
	rm -rf *.o
	./astar

dijkstra: prerequisites
	cc -c astar.c
	cc dijkstra.c data_reader.o maze_structure.o astar.o -o dijkstra
	rm -rf *.o
	./dijkstra

bellman-ford: prerequisites
	cc -c astar.c
	cc bellman-ford.c data_reader.o maze_structure.o astar.o -o bellman-ford
	rm -rf *.o
	./bellman-ford

right-hand: prerequisites
	cc right-hand.c data_reader.o maze_structure.o -o right-hand
	rm -rf *.o
	./right-hand

prerequisites:
	cc -c data_reader.c
	cc -c maze_structure.c

clean:
	rm -rf *.o


clean-artifacts:
	rm dfs bfs random right-hand bellman-ford astar dijkstra