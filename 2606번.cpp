#include <iostream>
#include <queue>
using namespace std;
int Graph[1001][1001];
int N, M;
int visited[1001];
void BFS(int startx)
{
	queue <int> q;
	q.push(startx);
	visited[startx] = 1;
	while (!q.empty())
	{
		int front = q.front();
		q.pop();
		//count++;
		for (int i = 1; i <= N; i++)
		{
			if (Graph[front][i] == 1 && visited[i] == 0)
			{
				visited[i] = 1;
				q.push(i);
			}
		}
	}
}
int main()
{
	int count = 0;
	cin >> N >> M;
	for (int i = 1; i <= M; i++)
	{
		int a, b;
		cin >> a >> b;
		Graph[a][b] = Graph[b][a] = 1;
	}
	BFS(1);
	for (int i = 1; i <= N; i++)
	{
		//printf("%d ", visited[i]);
	
		if (visited[i] == 1)
		{
			//printf("방문한 점은: %d\n", i);
			count++;
		}
		
	}
	printf("%d", count - 1);
}