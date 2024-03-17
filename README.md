# PathFindingAlgorithms
## Kompilacja
Program kompilowany jest przy użyciu pliku Makefile poprzez wywołanie w środowisku Unix komendy 
```make```
Dla każdego algorytmu przygotowany został osobny moduł kompilujący, który jednocześnie uruchamia programy na przypisanych do nich parametrach
### AStar
```make astar```
### Bellman-Ford
```make bellman-ford```
### BFS
```make bfs```
### DFS
```make dfs```
### Dijkstra
```make dijkstra```
### Random
```make random```
### Right-hand
```make right-hand```

W celu usunięcia wszelkich artefaktów (plików wykonywalnych któregokolwiek z efektów kompilacji, należy wywołać polecenie
```make clean-artifacts```
## Uruchomienie programu
Program(y) uruchamiane są w trakcie kompilacji (jednorazowo). Można także ponownie je wywołać wykonując odpowiednie polecenia:
### AStar
```./astar```
### Bellman-Ford
```./bellman-ford```
### BFS
```./bfs```
### DFS
```./dfs```
### Dijkstra
```./dijkstra```
### Random
```./random```
### Right-hand
```./right-hand```
## Przypadki testowe
W projekcie znajdują się także pliki testowe dla których przeprowadzone zostały pomiary efektywności pamięciowe i czasowe. Znajdują się one w folderze TestCases.
Można dodać swój przypadek testowy. Należy jednak pamiętać, aby labirynt dla przypadku testowego miał początek w prawym górny rogu labiryntu, a koniec w lewym dolnym rogu.
Można także zmodyfikować kod aby poprawnie odczytywał początek i koniec i ustrzec się od tego typu konieczności.
## Uruchamianie przypadków testowych
Aby uruchomić algorytm dla przypadku testowego, należy w pliku .c dla danego algorytmu zamienić nazwę pliku wczytywanego jako strukturę (w funkcji main każdego algorytmu).
Można także zastąpić wprowadzanie z ręki wczytywaniem na podstawie parametru startowego.
