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
				visited[i][j] = 0; //�ʱ�ȭ
			}
		}
		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= M; j++)
			{
				if (Graph[i][j] == 2 && visited[i][j] == 0)
				{
					DFS(i, j);  //���̷����� �ִ� �κк��� ���� ��
					visited[i][j] = 1;
				}
			}
		}
	}
	else { //�������
		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= M; j++)
			{
				if (Graph[i][j] == 0)
				{
					Graph[i][j] = 1;
					obtacal(count + 1);
					Graph[i][j] = 0; //�㹰���� �ʱ�ȭ ������ ��
				}
			}
		}
	}
	if (result == 0) result = virus;
	else result = min(result, virus);
}
void DFS(int startx, int starty)
{
	virus++; //���̷��������ĵɼ��ִ� ���� ��
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
	int ans = N * M - (wall + 3 + result);  //��ü���� ��, �߰����غ�(3), ���̷����� ���� �������ο���
	printf("%d", ans);
}