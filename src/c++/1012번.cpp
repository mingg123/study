#include <iostream>
#include <queue>
using namespace std;
int T;
int Graph[51][51];
int visited[51][51];
int direct[4][2] = { {1,0},{0,1},{-1,0},{0,-1} };
int ans[51];
void init(int M, int N)
{
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			Graph[j][i] = 0; //0을 초기화
			visited[j][i] = 0;
		}
	}
}
void BFS(int startx, int starty, int M, int N)
{
	queue <pair<int,int>> q;
	q.push({ startx, starty });
	visited[startx][starty] = 1;
	while (!q.empty())
	{
		int stx = q.front().first;
		int sty = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int ntx = stx + direct[i][0];
			int nty = sty + direct[i][1];
			if (ntx >= 0 && ntx < M && nty >=0 && nty < N && Graph[ntx][nty] == 1 && visited[ntx][nty] == 0)
			{
				q.push({ ntx,nty });
				visited[ntx][nty] = 1;
			}
		}
	}
}
int main()
{
	cin >> T;
	for (int k = 0; k < T; k++)
	{
		int M, N, K;
		cin>> M >> N >> K;
		init(M,N);
		for (int i = 0; i < K; i++)
		{
			int a, b;
			cin >> a >> b;
			Graph[a][b] = 1;
		}
		int cnt = 0;
		for (int i = 0; i <N; i++)
		{
			for (int j = 0; j <M; j++)
			{
				if (Graph[j][i] == 1 && visited[j][i] == 0)
				{
					BFS(j, i,M,N);
					cnt++;
				}
			}
		}
		ans[k] = cnt;
	}
	for (int i = 0; i < T; i++)
	{
		cout << ans[i] << endl;
	}
}
