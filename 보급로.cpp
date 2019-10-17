#include <iostream>
#include <queue>
using namespace std;
int N;
int Graph[101][101];
int visitied[101][101];
int d[101][101];
int direct[4][2] = { {1,0},{0,1},{-1,0},{0,-1} };
void init()
{
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			Graph[i][j] = 0;
			visitied[i][j] = 0;
			d[i][j] = 987654321;
		}
	}
}
void BFS()
{
	queue <pair<int, int>> q;
	q.push({ 1,1 });
	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int nextx = x + direct[i][0];
			int nexty = y + direct[i][1];
			if (nextx >= 1 && nexty >= 1 && nextx <= N && nexty <= N)
			{
				if (visitied[nextx][nexty] == 0 || d[nextx][nexty] > d[x][y] + Graph[nextx][nexty])
				{
					d[nextx][nexty] = d[x][y] + Graph[nextx][nexty];
					visitied[nextx][nexty] = 1;
					q.push({ nextx, nexty });
				}
			}
		}
	}
}
int main()
{
	int tc;
	cin >> tc;
	for (int z = 1; z <= tc; z++)
	{
		cin >> N;
		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= N; j++)
			{
				int a;
				scanf_s("%1d", &a);
				Graph[i][j] = a;
				d[i][j] = 987654321;
			}
		}
		d[1][1] = 0;
		BFS();
		cout <<"#"<<z<<" "<< d[N][N] << endl;
		init();
	}
}