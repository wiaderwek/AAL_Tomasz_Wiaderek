#pragma once
#include<vector>
#include<iostream>

using namespace std;

class Graph
{
private:

	class Vertex
	{
	private:
		int mNumber;
		int mValue;
		vector<int> mNextVertices;

	public:
		Vertex(int number, int value)
		{
			mNumber = number;
			mValue = value;
		}

		Vertex(int number, int value, vector<int> nextVertices)
		{
			mNumber = number;
			mValue = value;
			mNextVertices = nextVertices;
		}

		void setNextVertices(vector<int> nextVertices)
		{
			mNextVertices = nextVertices;
		}

		void addNextVertex(int nextVertex)
		{
			mNextVertices.push_back(nextVertex);
		}

		int getNumber() 
		{
			return mNumber;
		}

		int getValue()
		{
			return mValue;
		}

		vector<int> getNextVertices()
		{
			return mNextVertices;
		}

		int getNumberOfNextVerices()
		{
			return mNextVertices.size();
		}
		
		void show()
		{
			cout << mNumber << ": ";
			for (int i = 0; i < mNextVertices.size(); ++i)
			{
				cout << mNextVertices[i] << " ";
			}
			cout << endl;
		}
	};

	int mNumberOfEdges;
	int mNumberOfVertices;
	vector<Vertex> mEdges;

	void createEdge(int vertex1, int vertex2);
	void loadGraphFormFile(string vertexFile, string edgesFile);
	int valueOfthePath(vector<int> path);
	int getValueOfVertex(int vertex);
	int getNumberOfNextVerticesForVertex(int vertex);
	vector<int> getNextVerticesForVertex(int vertex);
	bool isVertexVisitedInPath(int vertex, vector<int> path);

public:
	Graph();
	Graph(string vertexFile, string edgesFile);
	vector<int> findPath(int src, int dst, int value);
	void show();
};

