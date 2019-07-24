#include <iostream>
#include <stdio.h>
#include <stack>
#include <queue>
using namespace std;
int visitedBFS[1001];
int visitedDFS[1001];
int Graph[1001][1001];
int N, M;
void DFS(int startx)
{
	stack <int> s;
	s.push(startx);
	while (!s.empty())
	{
		int front = s.top();
		s.pop();
		if (visitedDFS[front] == 0)
		{
			printf("%d ", front);
		}
		visitedDFS[front] = 1;
		
		for (int i = N; i >= 1; i--)
		{
			if (Graph[front][i] == 1 && visitedDFS[i] == 0)
			{
				s.push(i);
				//printf("≥÷æÓ¡ÿ : %d\n", i);
			}
		}
	}
	
}
void BFS(int startx)
{
	queue <int> q;
	q.push(startx);
	visitedBFS[startx] = 1;
	while (!q.empty())
	{
		int front = q.front();
		printf("%d ", front);
		q.pop();
		for (int i = 1; i <= N; i++)
		{
			if (Graph[front][i] == 1 && visitedBFS[i] == 0)
			{
				q.push(i);
				visitedBFS[i] = 1;
			}
		}
	}
}
int main()
{
	cin >> N >> M;
	int x;
	cin >> x;
	for (int i = 1; i <= M; i++)
	{
		int a, b;
		cin >> a >> b;
		Graph[a][b] = Graph[b][a] = 1;
	}
	DFS(x);
	printf("\n");
	BFS(x);
}