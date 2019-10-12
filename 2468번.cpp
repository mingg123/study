#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
int N;
int Graph[1001][1001];
int direct[4][2] = { {1,0},{0,1},{-1,0},{0,-1} };
int visitied[1001][1001];
int num[101];
int ans;
void init()
{
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			visitied[i][j] = 0;
		}
	}
}
void DFS(int x, int y, int h)
{
	visitied[x][y] = 1;
	for (int i = 0; i < 4; i++)
	{
		int nextx = x + direct[i][0];
		int nexty = y + direct[i][1];
		if (nextx >= 1 && nexty >= 1 && nextx <= N && nexty <= N && visitied[nextx][nexty] == 0&& Graph[nextx][nexty]> h)
		{
			DFS(nextx, nexty,h);
		}
	}
}
int main()
{
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

	for (int k = 0; k < 100; k++)
	{
		init();
		int cnt = 0;
		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= N; j++)
			{
				if (Graph[i][j] > k && visitied[i][j] == 0)
				{
					cnt++;
					DFS(i, j, k);
				}
				
			}
		}
		if (cnt == 0)
		{
			num[k] = 1;
		}
		else 
		num[k] = cnt;
	}
	sort(num,  num+ 100);
	cout << num[99] << endl;
	//cout << cnt + 1 << endl;
	
	for (int i = 0; i < 100; i++)
	{
		cout << num[i] << " ";
	}
	
}