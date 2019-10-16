#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
int M, N, sx, sy, hour;
int Graph[51][51];
int visitied[51][51];
int direct[5][2] = { {0,0},{0,1},{-1,0},{0,-1},{1,0} };
struct s {
	int x, y, dir, h;
};
void init()
{
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			Graph[i][j] = 0;
			visitied[i][j] = 0;
		}
	}
}
void BFS(int stx, int sty, int dir, int hour)
{

	queue<s> q;
	q.push({ stx,sty,dir,1 });
	visitied[stx][sty] = 1;
	while (!q.empty())
	{
		int x = q.front().x;
		int y = q.front().y;
		int hour1 = q.front().h;
		int dir = q.front().dir;
		//cout << x<<" " << y <<" "<< hour1 << endl;
		q.pop();
		if (hour1 < hour) {
			for (int i = 1; i <= 4; i++)
			{
				int nextx = x + direct[i][0];
				int nexty = y + direct[i][1];
				int nextdirect = Graph[nextx][nexty];
				if (nextdirect != 0)
				{
					if (dir == 1)
					{
						if (nextx >= 0 && nexty >= 0 && nextx < M && nexty < N && Graph[nextx][nexty] != 0 && visitied[nextx][nexty] == 0)
						{
							if (i == 1 && ((nextdirect == 2) || (nextdirect == 4) || (nextdirect == 5))) continue;
							if (i == 2 && ((nextdirect == 3) || (nextdirect == 4) || (nextdirect == 7))) continue;
							if (i == 3 && ((nextdirect == 2) || (nextdirect == 6) || (nextdirect == 7))) continue;
							if (i == 4 && ((nextdirect == 3) || (nextdirect == 5) || (nextdirect == 6))) continue;
							q.push({ nextx, nexty, nextdirect, hour1 + 1 });
							visitied[nextx][nexty] = 1;
						}
					}
					if (dir == 2)
					{
						if (nextx >= 0 && nexty >= 0 && nextx < M && nexty < N && Graph[nextx][nexty] != 0 && visitied[nextx][nexty] == 0)
						{
							if (i == 1 || i == 3) continue;
							if (i == 2 && ((nextdirect == 3) || (nextdirect == 4) || (nextdirect == 7))) continue;
							if (i == 4 && ((nextdirect == 3) || (nextdirect == 5) || (nextdirect == 6))) continue;
							q.push({ nextx, nexty, nextdirect, hour1 + 1 });
							visitied[nextx][nexty] = 1;
						}
					}
					if (dir == 3)
					{
						if (nextx >= 0 && nexty >= 0 && nextx < M && nexty < N && Graph[nextx][nexty] != 0 && visitied[nextx][nexty] == 0)
						{
							if (i == 2 || i == 4) continue;
							if (i == 1 && ((nextdirect == 2) || (nextdirect == 4) || (nextdirect == 5))) continue;
							if (i == 3 && ((nextdirect == 2) || (nextdirect == 6) || (nextdirect == 7))) continue;
							q.push({ nextx, nexty, nextdirect, hour1 + 1 });
							visitied[nextx][nexty] = 1;
						}
					}
					if (dir == 4)
					{
						if (nextx >= 0 && nexty >= 0 && nextx < M && nexty < N && Graph[nextx][nexty] != 0 && visitied[nextx][nexty] == 0)
						{
							if (i == 3 || i == 4) continue;
							if (i == 1 && ((nextdirect == 2) || (nextdirect == 4) || (nextdirect == 5))) continue;
							if (i == 2 && ((nextdirect == 3) || (nextdirect == 4) || (nextdirect == 7))) continue;
							q.push({ nextx, nexty, nextdirect, hour1 + 1 });
							visitied[nextx][nexty] = 1;
						}
					}
					if (dir == 5)
					{
						if (nextx >= 0 && nexty >= 0 && nextx < M && nexty < N && Graph[nextx][nexty] != 0 && visitied[nextx][nexty] == 0)
						{
							if (i == 2 || i == 3) continue;
							if (i == 1 && ((nextdirect == 2) || (nextdirect == 4) || (nextdirect == 5))) continue;
							if (i == 4 && ((nextdirect == 3) || (nextdirect == 5) || (nextdirect == 6))) continue;
							q.push({ nextx, nexty, nextdirect, hour1 + 1 });
							visitied[nextx][nexty] = 1;
						}
					}
					if (dir == 6)
					{
						if (nextx >= 0 && nexty >= 0 && nextx < M && nexty < N && Graph[nextx][nexty] != 0 && visitied[nextx][nexty] == 0)
						{
							if (i == 1 || i == 2) continue;
							if (i == 3 && ((nextdirect == 2) || (nextdirect == 6) || (nextdirect == 7))) continue;
							if (i == 4 && ((nextdirect == 3) || (nextdirect == 5) || (nextdirect == 6))) continue;
							q.push({ nextx, nexty, nextdirect, hour1 + 1 });
							visitied[nextx][nexty] = 1;
						}
					}
					if (dir == 7)
					{
						if (nextx >= 0 && nexty >= 0 && nextx < M && nexty < N && Graph[nextx][nexty] != 0 && visitied[nextx][nexty] == 0)
						{
							if (i == 1 || i == 4) continue;
							if (i == 2 && ((nextdirect == 3) || (nextdirect == 4) || (nextdirect == 7))) continue;
							if (i == 3 && ((nextdirect == 2) || (nextdirect == 6) || (nextdirect == 7))) continue;
							q.push({ nextx, nexty, nextdirect, hour1 + 1 });
							visitied[nextx][nexty] = 1;
						}
					}
				}
			}
		}
	}
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++)
	{
		cin >> M >> N >> sx >> sy >> hour;
		for (int i = 0; i < M; i++)
		{
			for (int j = 0; j < N; j++)
			{
				int a;
				cin >> a;
				Graph[i][j] = a;
			}
		}
		BFS(sx, sy, Graph[sx][sy], hour);
		//cout << endl;
		int cnt = 0;
		for (int i = 0; i < M; i++)
		{
			for (int j = 0; j < N; j++)
			{
				if (visitied[i][j] == 1)
					cnt++;
				//cout << visitied[i][j] << " ";
			}
			//cout << endl;
		}
		cout <<"#"<<t<<" "<<cnt << endl;
		init();
	}
}