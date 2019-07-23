#include <iostream>
using namespace std;
int Graph[1001][1001];
int N; 
int M;
int num;
int map[1001][1001];
int d[1002]; //방향 저장소
int direct1[2] = { 0, 1}; //동
int direct2[2] = { 0,-1 }; //서
int direct3[2] = { -1,0 }; //북
int direct4[2] = { 1,0 }; //남
void change( int &nextx, int &nexty, int dd, int flag)
{
	
	//printf("다음위치는 %d %d %d  flag는 : %d \n", nextx, nexty, dd, flag);
	
	if (dd == 1) //동쪽인경우
	{
		int first = Graph[1][0];
		int second = Graph[1][1];
		int third = Graph[1][2];
		int fouth = Graph[3][1];
		Graph[1][1] = first;
		Graph[1][2] = second;
		Graph[1][0] = fouth;
		Graph[3][1] = third;
	}
	
	if (dd == 2)  //서쪽인경우
	{
		int first = Graph[1][0];
		int second = Graph[1][1];
		int third = Graph[1][2];
		int fouth = Graph[3][1];
		Graph[1][1] = third;
		Graph[1][2] = fouth;
		Graph[1][0] = second;
		Graph[3][1] = first;
	}
	
	if (dd == 3) //북쪽인경우
	{
		int first = Graph[0][1];
		int second = Graph[1][1];
		int third = Graph[2][1];
		int fouth = Graph[3][1];
		Graph[0][1] = second;
		Graph[1][1] = third;
		Graph[2][1] = fouth;
		Graph[3][1] = first;
	}
	
	if (dd == 4)  //남쪽인경우
	{
		int first=Graph[0][1];
		int second = Graph[1][1];
		int third = Graph[2][1];
		int fouth = Graph[3][1];
		Graph[0][1] = fouth;
		Graph[1][1] = first;
		Graph[2][1] = second;
		Graph[3][1] = third;
	
	}
	int n = map[nextx][nexty];
	int m = Graph[3][1];
	if (n != 0)
	{
		Graph[3][1] = n;
		map[nextx][nexty] = 0;
		//printf("바닥값 : Graph[3][1] : %d\n", Graph[3][1]);
	}
	if (n == 0)
	{
	
			map[nextx][nexty] = m;
		
		
	}
	if (flag == 0)
	{
		printf("%d\n", Graph[1][1]);
	}
}
void move(int startx, int starty, int count, int flag)
{	
	
	flag = 0;
	int dd = 0;
	if (count == num+1)
	{
		return;
	}
	//printf("시작위치와 플래그: %d %d %d %d\n", startx, starty, count, flag);
	int nextx = 0;
	int nexty = 0;
	if (d[count] == 1) //동쪽이면
	{
		nextx = startx + direct1[0];
		nexty = starty + direct1[1];
		dd = 1;
	}
	else if (d[count] == 2)  //서쪽
	{
		nextx = startx + direct2[0];
		nexty = starty + direct2[1];
		dd = 2;
	}
	else if (d[count] == 3) //북쪽
	{
		nextx = startx + direct3[0];
		nexty = starty + direct3[1];
		dd = 3;
	}
	else if (d[count] == 4) //남쪽
	{
		nextx = startx + direct4[0];
		nexty = starty + direct4[1];
		dd = 4;
	}
	//cout << count << "번째일때";
	//printf("다음 위치: %d %d %d flag : %d\n", nextx, nexty, count, flag);
	if (nextx <0 || nextx >=N  || nexty <0 || nexty >=M)
	{
		flag = 1;
		move( startx, starty, count + 1, flag);
	}
	if (flag != 1)
	{
		change( nextx, nexty, dd, flag);
		move( nextx, nexty, count + 1, flag);
	}
}
int main()
{
	int x, y;
	cin >> N >> M;
	cin >> x >> y; //주사위 시작위치
	cin >> num; 
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			int a, b;
			cin >> a;
			map[i][j] = a;
		}
	}
	for (int i = 1; i <= num; i++)
	{
		int c;
		cin >> c;
		d[i] = c;
	}
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			Graph[i][j] = 0;

		}
		//printf("\n");
	}
	//printf("%d", Graph[1][1]);
	move(x,y,1,0);
	
	
	//printf("맵은: \n");
	/*
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			printf("%d", map[i][j]);
		}
		printf("\n");
	}
	printf("주사위는 \n");

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			printf("%d", Graph[i][j]);
		}
		printf("\n");
	}
	*/
}