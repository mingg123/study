#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <vector>
using namespace std;
int cnt[1001];
int Graph[1001][1001];
int visited[1001][1001];
int N;
int direct[4][2] = { {0,1}, {-1,0}, {1,0}, {0,-1} };
void DFS(int startx, int starty, int count)
{
	cnt[count]++;
	//printf("시작점은: %d %d %d \n", startx, starty, count);
	visited[startx][starty] = 1;
	for (int i = 0; i < 4; i++)
	{
		int nextx = startx + direct[i][0];
		int nexty = starty + direct[i][1];
		if (nextx>=1 && nextx <=N && nexty >=1 && nexty <= N && Graph[nextx][nexty] == 1 && visited[nextx][nexty]==0)
		{
			//printf("다음으로갈 값 %d %d\n", nextx, nexty);
			DFS(nextx, nexty, count);
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
			int num;
			scanf_s("%1d", &num);
			Graph[i][j] = num;
		}
	}
	int count = 0;
	
	for (int i = 1; i <= N; i++)
	{
		
		for (int j = 1; j <= N; j++)
		{
			if (Graph[i][j] == 1&& visited[i][j]==0)
			{
				DFS(i, j, count);
				count++;
			}
		}
	}
	printf("%d\n", count);
	printf("정렬전\n");
	for (int i = 0; i < count; i++)
	{
		printf("%d", cnt[i]);
	}
	sort(cnt, cnt + count);

	for (int i = 0; i < count; i++)
	{
		
		printf("%d\n", cnt[i]);
	}
	
}