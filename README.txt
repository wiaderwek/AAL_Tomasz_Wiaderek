Intrukcja kompilacji:
W folderze ze wszytskmi plikami źródłowmi w terimnalu wpisujemy komędę:

>>make all

Jeśli kompilacja przebiegła prawidłowo program można uruchomić wpisując w terminalu komędę:

>>./program <plik z wierzchołkami> <plik z krawedziami> <wierzchołek początkowy> <wierzchołek końcowy> <warotść ścieżki>

np.:

>>./program vertices.txt edges.txt 1 6 10

Przykładowe dane wejściowe (nietrywialne):

1.
vertices1.txt edges1.txt
1 - 2 - 4 - 3 - 10 - 9 - 8 - 11
suma: 27

>>./program vertices1.txt edges1.txt 1 11 27

2.
vertices2.txt edges2.txt
1 - 2 - 5 - 7 - 10 - 11 - 12 - 8 - 6 - 3 - 4
suma: 74

>>./program vertices2.txt edges2.txt 1 4 74

3.
vertices3.txt edges3.txt
2 - 11 - 13 -12 -9 -6 -17 -16 - 15 - 8 - 7- 5 - 1 - 3 - 4 - 10
suma: 146

>>./program vertices3.txt edges3.txt 2 10 146

