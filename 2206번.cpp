#include <iostream>
#include <queue>
using namespace std;
int Graph[1001][1001];
int N, M;
int visited[1001][1001];
int direct[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };
struct wall {
	int x, y, wall;
};
queue <wall> q;
void BFS(int startx, int starty, int n, int m)
{
	q.push({ startx, starty,1 });
	visited[startx][starty] = 1;
	while (!q.empty())
	{
		int frontx = q.front().x;
		int fronty = q.front().y;
		int wall = q.front().wall;
		if (frontx == n && fronty == m)
		{
			printf("%d", visited[frontx][fronty] );
			return;
		}
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int nextx = frontx + direct[i][0];
			int nexty = fronty + direct[i][1];
			if (nextx >= 1 && nextx <= n && nexty >= 1 && nexty <= m && Graph[nextx][nexty] == 1 && wall == 1)
			{
				q.push({ nextx, nexty, wall - 1 });
				visited[nextx][nexty] = visited[frontx][fronty] + 1;
			}
			else if (nextx >= 1 && nextx <= n && nexty >= 1 && nexty <= m && Graph[nextx][nexty] == 0 && visited[nextx][nexty] == 0)
			{
				q.push({ nextx, nexty, wall });
				visited[nextx][nexty] = visited[frontx][fronty] + 1;
			}
		}
	}
	printf("-1\n");
}
int main()
{
	cin >> N >> M;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			int a;
			scanf_s("%1d", &a);
			Graph[i][j] = a;
		}
	}
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			//printf("%d", Graph[i][j]);
		}
	}
	BFS(1, 1, N, M);
}