#include <iostream>
#include <queue>
using namespace std;
int N, L, R;
int Graph[1001][1001];
int visited[1001][1001];
int direct[4][2] = { {1,0}, {0,1}, {-1,0},{0,-1} };
int cnt;
int ccnt;
void realinit()
{
	ccnt = 1;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			if (visited[i][j] != 0)
				ccnt=0;
			visited[i][j] = 0;
		}
	}
}
void ans(int count)
{
	/*
	cout << "visited" << endl;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			cout << visited[i][j] << " ";
		}
		cout << endl;
	}
	cout << "count: " << count << endl;
	*/
	int num = 0;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			if (visited[i][j] == 1)
			{
				num = Graph[i][j] + num;
			}
		}
	}
	int newnum = num / (count);
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			if (visited[i][j] == 1)
			{
				Graph[i][j] = newnum;
				visited[i][j] = 2;
			}
		}
	}
	/*
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			cout << Graph[i][j] << " ";
		}
		cout << endl;
	}
	*/
}
void BFS(int x, int y)
{
	queue <pair <int, int>> q;
	q.push({ x,y });
	//visited[x][y] = 1;
	cnt = 0;
	while (!q.empty())
	{
		int stx = q.front().first;
		int sty = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int ntx = stx + direct[i][0];
			int nty = sty + direct[i][1];
			int diff1 = Graph[stx][sty] - Graph[ntx][nty];
			int diff2 = Graph[ntx][nty] - Graph[stx][sty];
			if (ntx >= 1 && nty >= 1 && ntx <= N && nty <= N && visited[ntx][nty] == 0 && ((diff1 >= L && diff1 <= R) || (diff2 >= L && diff2 <= R)))
			{
				q.push({ ntx, nty });
				visited[ntx][nty] = 1;
				cnt++;
			}
		}
	}
	if (cnt != 0)
	{
		ans(cnt);
	}
}
int main() {
	cin >> N >> L >> R;

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			int a;
			cin >> a;
			Graph[i][j] = a;
		}
	}
	//BFS(1, 1);
	int realcnt = 0;
	for(;;)
	{ 
		if (ccnt == 1)
			break;
		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= N; j++)
			{
				if (visited[i][j] == 0)
				{
					BFS(i, j);
				}
				if (i == N && j == N)
				{
					realinit();
					realcnt++;
					//cout << "초기화한다" << endl;
				}
			}

		}
	}
	cout << realcnt-1 << endl;
	/*
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			cout << Graph[i][j] << " ";
		}
		cout << endl;
	}
	*/
}