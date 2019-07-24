#include <iostream>
#include <queue>
using namespace std;
int Graph[1001][1001];
int visitedDFS[1001];
int visitedBFS[1001];
int N, M;
void DFS(int startx)
{
	printf("%d ", startx);
	visitedDFS[startx] = 1;
	for (int i = 1; i <= N; i++)
	{
		if (Graph[startx][i] == 1 && visitedDFS[i] == 0)
		{
			DFS(i);
		}
	}
}
void BFS(int startx)
{
	queue <int> q;
	visitedBFS[startx] = 1;
	q.push(startx);
	
	while (!q.empty())
	{
		int front = q.front();
		printf("%d ", front);
		q.pop();
		for (int i = 1; i <= N; i++)
		{
			int nextx = i;
			if (Graph[front][i] == 1&& visitedBFS[nextx]==0)
			{
				visitedBFS[nextx] = 1;
				q.push(nextx);
				//printf("%d ", nextx);
			}
		}
		
	}
}
int main()
{
	cin >> N;
	cin >> M; 
	int start;
	cin >> start;
	for (int i = 1; i <= M; i++)
	{
			int a, b;
			cin >> a >> b;
			Graph[a][b] = Graph[b][a] = 1;
		
	}
	/*
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			printf("%d ", Graph[i][j]);
		}
		printf("\n");
	}
	*/
	DFS(start);
	printf("\n");
	BFS(start);
}