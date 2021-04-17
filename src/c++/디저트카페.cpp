#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;
int N;
int Graph[21][21];
int visitied[101];
int direct[4][2] = { {-1,-1},{1,-1},{-1,1},{1,1} };
int checkdir[4];
int ans;
void init()
{
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			Graph[i][j] = 0;
		}
	}
}
void DFS(int startx, int starty, int nextx, int nexty, int cnt, int dir)
{
	if (startx == nextx && starty == nexty)
	{
		ans = max(ans, cnt);
		return;
	}
	for (int i = 0; i <4; i++)
	{
		if ((i == 0 && dir == 3) || (i == 1 && dir == 2) || (i == 2 && dir == 1) || (i == 3 && dir == 0)) continue;
		if (i != dir && checkdir[i] == 1) continue;
		int nx = nextx + direct[i][0];
		int ny = nexty + direct[i][1];
		if (nx >= 1 && ny >= 1 && nx <= N && ny <= N)
		{
			if (nx == startx && ny == starty)
			{
				DFS(startx, starty, nx, ny, cnt, i);
			}

			int nxnum = Graph[nx][ny];
			if (visitied[nxnum] == 1)continue;

			visitied[nxnum] = 1;
			checkdir[i] = 1;
			DFS(startx, starty, nx, ny, cnt + 1, i);
			visitied[nxnum] = 0;
			checkdir[i] = 0;
		}
	}
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int TC;
	cin >> TC;
	for (int t = 1; t <= TC; t++)
	{
		ans = -987654321;
		cin >> N;
		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= N; j++)
			{
				int a;
				cin >> a;
				Graph[i][j] = a;
			}
		}

	
		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= N; j++)
			{
				int stnum = Graph[i][j];
				int nextx = i + direct[3][0];
				int nexty = j + direct[3][1];
				if (nextx >= 1 && nexty >= 1 && nextx <= N && nexty <= N)
				{
					int nxnum = Graph[nextx][nexty];
					if (nxnum != stnum)
					{
						visitied[stnum] = 1;
						visitied[nxnum] = 1;
						checkdir[3] = 1;
						DFS(i, j, nextx, nexty, 2, 3);
						visitied[stnum] = 0;
						visitied[nxnum] = 0;
						checkdir[3] = 0;
					}
				}
			}
		}
		if (ans == -987654321)
			cout <<"#"<<t<<""<<-1<< endl;
		else
			cout <<"#"<<t<<""<< ans << endl;
		init();
		memset(visitied, 0, sizeof(visitied));
		memset(checkdir, 0, sizeof(checkdir));
	}
}