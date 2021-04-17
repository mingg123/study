#include <iostream>
#include <stdio.h>
#include <queue>
using namespace std;
int N, M;
int Graph[301][301];
int Graph2[301][301];
int visitied[301][301];
int direct[4][2] = { {1,0},{0,1},{-1,0},{0,-1} };
queue <pair <int, int>> q;
void init()
{
	int c = 0;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			Graph[i][j] = Graph2[i][j];
			if (Graph2[i][j] != 0)
			{
				c++;
			}
			Graph2[i][j] = 0;
			visitied[i][j] = 0;
		}
	}
	if (c == 0)
	{
		cout << 0 << endl;
		return;
	}
}
void DFS(int x, int y)
{
	visitied[x][y] = 1;
	for (int i = 0; i < 4; i++)
	{
		int nextx = x + direct[i][0];
		int nexty = y + direct[i][1];
		if (Graph2[nextx][nexty] != 0 && visitied[nextx][nexty] == 0 && nextx >= 1 && nexty >= 1 && nextx <= N && nexty <= M)
		{
			DFS(nextx, nexty);
		}
	}
}

void first()
{
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			if (Graph[i][j] != 0)
			{
				int cnt = 0;
				for (int k = 0; k < 4; k++)
				{
					int nextx = i + direct[k][0];
					int nexty = j + direct[k][1];
					if (nextx >= 1 && nexty >= 1 && nextx <= N && nexty <= M && Graph[nextx][nexty] == 0)
					{
						cnt++;
					}
				}
				Graph2[i][j] = Graph[i][j] - cnt;
				if (Graph2[i][j] < 0)
				{
					Graph2[i][j] = 0;
				}
			}
		}
	}

}
int main()
{
	cin >> N >> M;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			int a;
			//cin >> a;
			scanf("%d", &a);
			Graph[i][j] = a;
		}
	}
	int ans = 0;
	for (;;)
	{
		ans++;
		first();
		int cnt = 0;
		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= M; j++)
			{
				if (Graph2[i][j] != 0 && visitied[i][j] == 0)
				{
					cnt++;
					DFS(i, j);
					if (cnt >= 2)
					{
						printf("%d\n", ans);
						//break;
						return 0;
					}
				}
			}
		}
		//cout << cnt << endl;

		init();
	}
	/*
	cout << endl;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			cout << Graph2[i][j] << " ";
		}
		cout << endl;
	}
	*/
}