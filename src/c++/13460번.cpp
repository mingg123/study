#include <iostream>
#include <queue>
#include <stdio.h>
using namespace std;
int N, M;
char Graph[101][101];
int direct[4][2] = { {0,1}, {1,0}, {-1,0}, {0,-1} };
int visited[101][101][101][101];
struct ball {
	int Rx, Ry, Bx, By, cnt;
};
queue <ball> q;
void move(int& x, int& y, int& c, int dx, int dy)
{
	//printf("함수불러와짐 x 값 %d %d\n ", x, y);
	for (;;)
	{
		if (Graph[x + dx][y + dy] == '#')
			break;
		if (Graph[x][y] == 'O')
			break;
		x = x + dx;
		y = y + dy;
		c++; //찾기위해몇번 움직였나
		//printf("x y 값 %d %d\n", x, y);
	}
}

void BFS() {
	while (!q.empty())
	{
		int Rx = q.front().Rx;
		int Ry = q.front().Ry;
		int Bx = q.front().Bx;
		int By = q.front().By;
		int cnt = q.front().cnt;
		q.pop();
		if (cnt >= 10)
		{
			break;
		}
		for (int i = 0; i < 4; i++)
		{
			int nextRx, nextRy, nextBx, nextBy;
			int rc = 0;
			int bc = 0;
			int count = cnt + 1;
			nextRx = Rx, nextRy = Ry, nextBx = Bx, nextBy = By;
			//printf("count; %d\n", count);

			move(nextRx, nextRy, rc, direct[i][0], direct[i][1]); //red움직임
			move(nextBx, nextBy, bc, direct[i][0], direct[i][1]); //blue 움직임

			if (Graph[nextBx][nextBy] == 'O')
				continue;
			if (Graph[nextRx][nextRy] == 'O')
			{
				printf("%d", count);
				return;
			}

			if (nextRx == nextBx && nextRy == nextBy)
			{
				if (rc > bc)
				{
					nextRx = nextRx - direct[i][0];
					nextRy = nextRy - direct[i][1];
				}
				else
				{
					nextBx = nextBx - direct[i][0];
					nextBy = nextBy - direct[i][1];
				}
			}
			if (visited[nextRx][nextRy][nextBx][nextBy] == 1)
				continue;
			visited[nextRx][nextRy][nextBx][nextBy] = 1;
			q.push({ nextRx, nextRy, nextBx, nextBy, count });

		}
	}
	printf("-1\n");
}
int main()
{
	cin >> N >> M;
	int rx = 0;
	int ry = 0;
	int bx = 0;
	int by = 0;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			char s;
			cin >> s;
			Graph[i][j] = s;
			if (Graph[i][j] == 'R')
			{
				rx = i;
				ry = j;
			}
			if (Graph[i][j] == 'B')
			{
				bx = i;
				by = j;
			}
		}
	}
	//printf("red 위치 %d %d blue 위치 %d %d\n", rx, ry, bx, by);
	q.push({ rx,ry,bx,by,0 });
	visited[rx][ry][bx][by] = 1;
	BFS();
}