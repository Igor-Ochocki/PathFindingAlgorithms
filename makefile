dfs: prerequisites
	cc ./Algorithms/dfs.c data_reader.o maze_structure.o -o dfs
	rm -rf *.o
	./dfs

bfs: prerequisites
	cc ./Algorithms/bfs.c data_reader.o maze_structure.o -o bfs
	rm -rf *.o
	./bfs

random: prerequisites
	cc ./Algorithms/random.c data_reader.o maze_structure.o -o random
	rm -rf *.o
	./random

astar: prerequisites wll
	cc ./Algorithms/astar.c data_reader.o maze_structure.o weighted_linked_list.o -o astar
	rm -rf *.o
	./astar

dijkstra: prerequisites wll
	cc ./Algorithms/dijkstra.c data_reader.o maze_structure.o weighted_linked_list.o -o dijkstra
	rm -rf *.o
	./dijkstra

bellman-ford: prerequisites wll
	cc ./Algorithms/bellman-ford.c data_reader.o maze_structure.o weighted_linked_list.o -o bellman-ford
	rm -rf *.o
	./bellman-ford

right-hand: prerequisites
	cc ./Algorithms/right-hand.c data_reader.o maze_structure.o -o right-hand
	rm -rf *.o
	./right-hand

wll:
	cc -c ./Data/weighted_linked_list.c

prerequisites:
	cc -c ./Data/data_reader.c
	cc -c ./Data/maze_structure.c

clean:
	rm -rf *.o


clean-artifacts:
	rm dfs bfs random right-hand bellman-ford astar dijkstra