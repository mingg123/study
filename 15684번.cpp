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
void ans(int x, int y, int count)  //��ٸ��� ����� �Լ�
{
	if (count > 3)   //count�� 3���� ũ�� ������ѹ��� 
	{
		return;
	}

		/*check();   //3�����̸�  check�Լ� ������ Ȯ��
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

bool check()  //1���� 1��, 2���� 2�� �°� �����ϴ��� Ȯ��
{
	//flag = 1;
	for (int i = 1; i <= N; i++)
	{
		int cnt = i; //����ġ�� ��Ÿ��
		for (int j = 1; j <= H; j++)
		{
			if (Graph[j][cnt] == 1 && cnt <= N)  //����ġ�� 2,2�ε� 2,2�� ��ٸ��������� 2,3���� �̵�
			{
				cnt = cnt + 1;
			}
			else if (Graph[j][cnt-1]==1&& cnt-1>=1)  //����ġ�� 2,2�ε� 2,1�� ��ٸ��������� 2,1�� �̵�
			{
				cnt = cnt - 1;
			}
		}
		if (cnt != i)  //Ʋ���� �����ϸ� flag=0���� �ٲ��� ����
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
	if (flag == 1)  //ó������ �ѹ濡 �����ϸ� 0���
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