#include <iostream>
#include <queue>
using namespace std;
int Graph[1001][1001];
int direct[4][2] = { {1,0},{0,1},{-1,0},{0,-1} };
int visitied[1001][1001][2];
int N, M;
struct wall {
	int x, y, wall1;
};
queue <wall> q;
void BFS()
{
	q.push({ 1,1,0 });
	visitied[1][1][0] = 1;
	while (!q.empty())
	{
		int x = q.front().x;
		int y = q.front().y;
		int wall = q.front().wall1;
		q.pop();
		if (x == N && y == M)
		{
			cout << visitied[N][M][wall] << endl;
			return;
		}
		for (int i = 0; i < 4; i++)
		{
			int nextx = x + direct[i][0];
			int nexty = y + direct[i][1];

			if (Graph[nextx][nexty] == 1 && wall == 0&& nextx>=1 && nexty>=1 && nextx<=N && nexty<=M)
			{
				q.push({ nextx, nexty, wall + 1 });
				visitied[nextx][nexty][wall+1] = visitied[x][y][wall] + 1;
			}
			else if (Graph[nextx][nexty] == 0 && nextx >= 1 && nexty >= 1 && nextx <= N && nexty <= M && visitied[nextx][nexty][wall]==0)
			{
			q.push({ nextx, nexty, wall });
			visitied[nextx][nexty][wall] = visitied[x][y][wall] + 1;
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
	BFS();
	
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			for (int k = 0; k <= 1; k++)
			{
				cout << visitied[i][j][k] << " ";
			}
		}
		cout << endl;
	}
	/*
	if (Graph[N][M] != 0)
	{
		cout << Graph[N][M] << endl;
	}
	else {
		cout << "-1" << endl;
	}
	*/
}