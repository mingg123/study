#include <iostream>
#include <algorithm>
using namespace std;
int N, M, H;
int Graph[1001][1001];
int flag;
int result = 9999;
void ans(int x, int y, int count);
void wall();
bool check();
void ans(int x, int y, int count)  //사다리를 세우는 함수
{
	if (count > 3)   //count가 3보다 크면 종료시켜버림 
	{
		return;
	}

		/*check();   //3이하이면  check함수 돌리며 확인
		if (flag == 1)
		{
			result = min(result, count);
			return;
		}
		*/
		if (check() == 1)
		{
			result = min(result, count);
			return;
		}
	
	for (int i = 1; i <= H; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			if (Graph[i][j] == 0)
			{
				Graph[i][j] = 1;
				ans(i, j, count+1);
				Graph[i][j] = 0;
			}
		}
	}
}

void wall()  
{
	for (int i = 1; i <= H; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			if (Graph[i][j] == 0)
			{
				Graph[i][j] = 1;
				ans(i, j, 1);
				Graph[i][j] = 0;
			}
		}
	}
}

bool check()  //1번이 1로, 2번이 2로 맞게 도착하는지 확인
{
	//flag = 1;
	for (int i = 1; i <= N; i++)
	{
		int cnt = i; //내위치를 나타냄
		for (int j = 1; j <= H; j++)
		{
			if (Graph[j][cnt] == 1 && cnt <= N)  //내위치가 2,2인데 2,2에 사다리가있으면 2,3으로 이동
			{
				cnt = cnt + 1;
			}
			else if (Graph[j][cnt-1]==1&& cnt-1>=1)  //내위치가 2,2인데 2,1에 사다리가있으면 2,1로 이동
			{
				cnt = cnt - 1;
			}
		}
		if (cnt != i)  //틀리게 도착하면 flag=0으로 바꾼후 종료
		{
			//flag = 0;
			return false;
		}
	}
	return true;
}
int main()
{
	cin >> N >> M >> H;
	for (int i = 0; i < M; i++)
	{
		int a, b;
		cin >> a >> b;
		Graph[a][b] = 1;
	}
	if (check() == 1)
	{
		printf("0\n");
		return 0;
	}
	/*
	if (flag == 1)  //처음부터 한방에 도착하면 0출력
	{
		printf("0\n");
	}
	*/
	wall();
	//printf("result: %d\n", result);
	if (result <= 3)
	{
		printf("%d\n", result);
	}
	else {
		printf("-1\n");
	}
	
}