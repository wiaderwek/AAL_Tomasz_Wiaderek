// AAL_Tomasz_Wiaderek.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//
#include <iostream>
#include "Graph.h"
#include <string>

using namespace std;

int main(int argc, char* argv[])
{
	if(argc < 6)
	{
		string help = argv[1];
		if(help == "help")
		{
			cout << "./program <file with vertices> <file with edges> ";
			cout << "<source vertex> <destination vertex> <value of path>" << endl;
		}
		else
		{
			cout << "Missing arguments!" << endl;
			return -1;
		}
	}
	else
	{
		string vertexFile = argv[1];
		string edgesFile = argv[2];
		int src = atoi(argv[3]);
		int dst = atoi(argv[4]);
		int value = atoi(argv[5]);

		Graph graph(vertexFile, edgesFile);
		vector<int> path;

		path = graph.findPath(src, dst, value);
		if (path.empty())
			cout << "brak sciezki" << endl;
		for (int i = 0; i < path.size(); ++i)
		{
			cout << path[i] << " ";
		}
		cout << endl;
		return 0;
	}
}

// Uruchomienie programu: Ctrl + F5 lub menu Debugowanie > Uruchom bez debugowania
// Debugowanie programu: F5 lub menu Debugowanie > Rozpocznij debugowanie

// Porady dotyczące rozpoczynania pracy:
//   1. Użyj okna Eksploratora rozwiązań, aby dodać pliki i zarządzać nimi
//   2. Użyj okna programu Team Explorer, aby nawiązać połączenie z kontrolą źródła
//   3. Użyj okna Dane wyjściowe, aby sprawdzić dane wyjściowe kompilacji i inne komunikaty
//   4. Użyj okna Lista błędów, aby zobaczyć błędy
//   5. Wybierz pozycję Projekt > Dodaj nowy element, aby utworzyć nowe pliki kodu, lub wybierz pozycję Projekt > Dodaj istniejący element, aby dodać istniejące pliku kodu do projektu
//   6. Aby w przyszłości ponownie otworzyć ten projekt, przejdź do pozycji Plik > Otwórz > Projekt i wybierz plik sln
