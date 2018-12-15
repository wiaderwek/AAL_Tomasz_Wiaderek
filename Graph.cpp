#include "Graph.h"
#include <fstream>
#include <iostream>
#include <queue>

Graph::Graph()
{
	mNumberOfEdges = 0;
	mNumberOfVertices = 0;
}

Graph::Graph(string vertexFile, string edgesFile)
{
	mNumberOfEdges = 0;
	mNumberOfVertices = 0;
	loadGraphFormFile(vertexFile, edgesFile);
}

void Graph::loadGraphFormFile(string vertexFile, string edgesFile)
{
	fstream fileWithVerices;
	fileWithVerices.open(vertexFile, ios::in);

	if (fileWithVerices.good())
	{
		std::cout << "Get access to the file!" << std::endl;
		int vertexNumber, valueOfVertex;
		fileWithVerices >> vertexNumber;
		fileWithVerices >> valueOfVertex;
		while (!fileWithVerices.eof())
		{
			mEdges.push_back(Vertex(vertexNumber, valueOfVertex));
			fileWithVerices >> vertexNumber;
			fileWithVerices >> valueOfVertex;
			++mNumberOfVertices;
		}
		fileWithVerices.close();
	}

	fstream fileWithEdges;
	fileWithEdges.open(edgesFile, ios::in);

	if (fileWithEdges.good())
	{
		std::cout << "Get access to the file!" << std::endl;
		int vertex1, vertex2;
		fileWithEdges >> vertex1;
		fileWithEdges >> vertex2;

		while (!fileWithEdges.eof())
		{
			createEdge(vertex1, vertex2);

			fileWithEdges >> vertex1;
			fileWithEdges >> vertex2;

			++mNumberOfEdges;
		}
		fileWithEdges.close();
	}
}

void Graph::createEdge(int vertex1, int vertex2)
{
	int added = 0;
	for (int i = 0; i < mEdges.size(); ++i)
	{
		if (mEdges[i].getNumber() == vertex1)
		{
			mEdges[i].addNextVertex(vertex2);
			++added;
		}
		else if (mEdges[i].getNumber() == vertex2)
		{
			mEdges[i].addNextVertex(vertex1);
			++added;
		}
		else if (added == 2)
		{
			return;
		}
	}
}

vector<int> Graph::findPath(int src, int dst, int value)
{
	queue<vector<int>> pathsToAnalize;

	vector<int> path;
	path.push_back(src);

	pathsToAnalize.push(path);

	while (!pathsToAnalize.empty())
	{
		path = pathsToAnalize.front();

		pathsToAnalize.pop();

		int last = path[path.size() - 1];

		if (last == dst)
		{
			if (valueOfthePath(path) == value)
			{
				return path;
			}
			else
			{
				continue;
			}
		}
		else
		{
			if (valueOfthePath(path) > value)
			{
				continue;
			}
		}

		for (int nextVertex : getNextVerticesForVertex(last))
		{
			if (!isVertexVisitedInPath(nextVertex, path))
			{
				vector<int> newPath(path);
				newPath.push_back(nextVertex);
				pathsToAnalize.push(newPath);
			}
		}
	}
	path.clear();

	return path;
}

int Graph::valueOfthePath(vector<int> path)
{
	int valueOfThePath = 0;
	for (int i = 0; i < path.size(); ++i)
	{
		valueOfThePath += getValueOfVertex(path[i]);
	}

	return valueOfThePath;
}

int Graph::getValueOfVertex(int vertex)
{
	for (int i = 0; i < mEdges.size(); ++i)
	{
		if (mEdges[i].getNumber() == vertex)
		{
			return mEdges[i].getValue();
		}
	}
}

int Graph::getNumberOfNextVerticesForVertex(int vertex)
{
	for (int i = 0; i < mEdges.size(); ++i)
	{
		if (mEdges[i].getNumber() == vertex)
		{
			return mEdges[i].getNumberOfNextVerices();
		}
	}
}

vector<int> Graph::getNextVerticesForVertex(int vertex)
{
	for (int i = 0; i < mEdges.size(); ++i)
	{
		if (mEdges[i].getNumber() == vertex)
		{
			return mEdges[i].getNextVertices();
		}
	}
}

bool Graph::isVertexVisitedInPath(int vertex, vector<int> path)
{
	for (int i = 0; i < path.size(); ++i)
	{
		if (path[i] == vertex)
		{
			return true;
		}
	}

	return false;
}

void Graph::show()
{
	for (int i = 0; i < mEdges.size(); ++i)
	{
		cout << mEdges[i].getNumber() << "  value: " << mEdges[i].getValue() << " : ";
		for (auto vertex : getNextVerticesForVertex(mEdges[i].getNumber()))
		{
			cout << vertex << " ";
		}
		cout << endl;
	}
}
