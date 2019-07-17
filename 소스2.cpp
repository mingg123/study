#include <iostream>
#include <algorithm>
using namespace std;
int Graph[1001][1001];
int visited[1001][1001];
int N, M;
int result, virus, wall = 0;
int direct[4][2] = { {0,1},{1,0},{0,-1},{-1,0} };
void DFS(int startx, int starty);
void obtacal(int count);

void obtacal(int count)
{
	if (count == 3)
	{
		virus = 0;
		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= M; j++)
			{
				visited[i][j] = 0; //초기화
			}
		}
		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= M; j++)
			{
				if (Graph[i][j] == 2 && visited[i][j] == 0)
				{
					DFS(i, j);  //바이러스가 있는 부분부터 갯수 셈
					visited[i][j] = 1;
				}
			}
		}
	}
	else { //벽세우기
		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= M; j++)
			{
				if (Graph[i][j] == 0)
				{
					Graph[i][j] = 1;
					obtacal(count + 1);
					Graph[i][j] = 0; //허물어줌 초기화 세웠던 벽
				}
			}
		}
	}
	if (result == 0) result = virus;
	else result = min(result, virus);
}
void DFS(int startx, int starty)
{
	virus++; //바이러스가전파될수있는 갯수 셈
	visited[startx][starty] = 1;
	for (int i = 0; i < 4; i++)
	{
		int nextx = startx + direct[i][0];
		int nexty = starty + direct[i][1];
		if (nextx > 0 && nextx <= N && nexty > 0 && nexty <= M && Graph[nextx][nexty] == 0 && visited[nextx][nexty] == 0)
		{
			visited[nextx][nexty] = 1;
			DFS(nextx, nexty);
		}

	}
}
int main()
{
	cin >> N >> M;
	for (int i = 1; i <=N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			int a;
			cin >> a;
			Graph[i][j] = a;
			if (Graph[i][j] == 1)
				wall++;
		}
	}
	obtacal(0);
	int ans = N * M - (wall + 3 + result);  //전체에서 벽, 추가해준벽(3), 바이러스를 빼면 안정적인영역
	printf("%d", ans);
}