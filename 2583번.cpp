#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;
int Graph[101][101];
int M, N, A;
int direct[4][2] = { {1,0},{0,1} ,{-1,0}, {0,-1} };
int visitied[101][101];
queue <pair <int, int>> q;
int num[101];
//vector <int> Graph[101];
//vector <int> visitied[101];

void DFS(int x, int y, int cnt)
{
	num[cnt]++;
	visitied[x][y] = 1;
	for (int i = 0; i < 4; i++)
	{
		int nextx = x + direct[i][0];
		int nexty = y + direct[i][1];
		if (nextx >= 0 && nexty >= 0 && nextx <N && nexty < M && Graph[nextx][nexty] == 0 && visitied[nextx][nexty] ==0)
		{
			DFS(nextx, nexty, cnt);
		}
	}
}
/*
void BFS(int sx, int sy, int nx, int ny)
{
	q.push({ sx, sy });
	Graph[sx][sy] = 1;
	visitied[sx][sy] = 2;
	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		//cout << x << " " << y << endl;
		for (int i = 0; i < 2; i++)
		{
			int nextx = x + direct[i][0];
			int nexty = y + direct[i][1];
			if (nextx <= nx - 1 && nexty <= ny - 1&& nextx>=0 && nexty>=0)
			{
				visitied[nextx][nexty] = 2;
				Graph[nextx][nexty] = 1;
				q.push({ nextx, nexty });
			}
		}
	}
}
*/
int main()
{
	cin >> M >> N >> A;
	//BFS(0, 2, 4, 4);
	int cnt = 0;
	for (int i = 0; i < A; i++)
	{
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		for (int i = c-1; i >= a; i--)
		{
			for (int j = b; j <= d - 1; j++)
			{
				Graph[i][j] = 1;
			}
		}
	}
	/*
	cout << endl;
	for (int i = M - 1; i >= 0; i--)
	{
		for (int j = 0; j < N; j++)
		{
			cout << Graph[j][i] << " ";
		}
		cout << endl;
	}
	*/

	for (int i = M - 1; i >= 0; i--)
	{
		for (int j = 0; j < N; j++)
		{
			if (Graph[j][i] == 0&& visitied[j][i]==0)
			{
				cnt++;
				DFS(j, i, cnt);

			}
		}

	}
	cout << cnt << endl;
	/*
	for (int i = 1; i <=cnt; i++)
	{
		cout << i << " : " << num[i] << endl;
	}
	*/
	sort(num+1, num + 1+ cnt);
	//cout << "Á¤·ÄÈÄ" << endl;
	for (int i = 1; i <= cnt; i++)
	{
		cout << num[i] << " ";
	}
	/*
	cout << endl;
	for (int i = M-1; i >= 0; i--)
	{
		for (int j =0; j <N; j++)
		{
			cout << Graph[j][i] << " ";
		}
		cout << endl;
	}
	*/
}