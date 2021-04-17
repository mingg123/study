#include <iostream>
using namespace std;
int direct[4][2] = { {0,1 }, { 1,0 }, { 0,-1 }, { -1,0 } };
int direct0[2] = {-1,0};  //북쪽
int direct1[2]=  {0,1};  //동쪽
int direct2[2] = {1,0}; //남쪽
int direct3[2] = {0,-1}; // 서쪽
int visited[1001][1001];
int Graph[1001][1001];
int N, M;
int count;
void DFS(int startx, int starty, int dd, int count)
{
	int nextx = 0;
	int nexty = 0;
	int backx = 0;
	int backy = 0;
	int d1 = 0; //변하는 방향
	if (dd == 0) //북이면 서쪽으로
	{
		nextx = startx + direct3[0];
		nexty = starty + direct3[1];
		d1 = 3;
		backx = startx + direct2[0];  //후진방향
		backy = starty + direct2[1];
	}
	else if (dd == 1) //동쪽이면 북쪽으로
	{
		nextx = startx + direct0[0];
		nexty = starty + direct0[1];
		d1 = 0;
		backx = startx + direct3[0];  //후진방향
		backy = starty + direct3[1];
	}
	else if (dd == 2) //남쪽이면 동쪽으로
	{
		nextx = startx + direct1[0];
		nexty = starty + direct1[1];
		d1 = 1;
		backx = startx + direct0[0];  //후진방향
		backy = starty + direct0[1];
	}
	else if (dd == 3) //서쪽이면 남쪽으로
	{
		nextx = startx + direct2[0];
		nexty = starty + direct2[1];
		d1 = 2;
		backx = startx + direct1[0];  //후진방향
		backy = starty + direct1[1];
	}
	visited[startx][starty] = 1;
	Graph[startx][starty] = 2; //청소한곳
	//printf("현위치: %d %d 다음위치: %d %d 뒷위치: %d %d %d\n", startx, starty, nextx, nexty,backx, backy ,count);
	int ax, ay = 0;
	int k = 0;
	for (int i = 0; i < 4; i++) //모든방향을 보기위한
	{
		ax = startx + direct[i][0];
		ay = starty + direct[i][1];
		if (Graph[ax][ay] == 2 || Graph[ax][ay] == 1) //벽이 있거나, 청소 했거나
		{
			k++;
		}
		
	}
	if (k == 4)
	{
		//printf("%d %d 4구역이 다 청소되어있습니다\n", startx, starty);
	}
	if (k == 4 && Graph[backx][backy] == 2)   //전부다 청소되어있다
	{
		//printf("현위치: %d %d 다음위치: %d %d 뒷위치: %d %d %d\n", startx, starty, nextx, nexty, backx, backy, count);
		//printf("전부다 청소되어있어 후진합니다.\n");
		DFS(backx, backy, dd, count);
	}
	else if (k == 4 && Graph[backx][backy] == 1) //모든방향이 벽이고, 후진했을때 1이 있으면 멈춰야함
	{
		//printf("멈춰야한다.\n");
		printf("%d\n", count);
		return;
	}
	 else if (visited[nextx][nexty] == 0 && Graph[nextx][nexty] == 0 ) //청소할 공간이 존재
	{
		//printf("현위치: %d %d 다음위치: %d %d 뒷위치: %d %d %d\n", startx, starty, nextx, nexty,backx, backy ,count);
		//printf("청소할 공간이 존재합니다.\n");
		DFS(nextx, nexty, d1, count + 1);
	}
	else if (Graph[nextx][nexty] != 0) //청소할 공간이없음
	{	
		//printf("현위치: %d %d 다음위치: %d %d 뒷위치: %d %d %d\n", startx, starty, nextx, nexty,backx, backy ,count);
		//printf("청소할 공간이 존재하지 않아 방향을 틉니다.");
		DFS(startx, starty, d1, count);
	}



}
int main()
{
	int x, y, d;
	cin >> N >> M;
	cin >> x >> y >> d;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j <M; j++)
		{
			int a;
			cin >> a;
			Graph[i][j] = a;
		}
	}

	for (int i = 0; i <N; i++)
	{
		for (int j = 0; j < M; j++)
		{
		//	printf("%d", Graph[i][j]);
		}
		//printf("\n");
	}
	DFS(x, y, d, 1);
}