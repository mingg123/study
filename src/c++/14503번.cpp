#include <iostream>
using namespace std;
int direct[4][2] = { {0,1 }, { 1,0 }, { 0,-1 }, { -1,0 } };
int direct0[2] = {-1,0};  //����
int direct1[2]=  {0,1};  //����
int direct2[2] = {1,0}; //����
int direct3[2] = {0,-1}; // ����
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
	int d1 = 0; //���ϴ� ����
	if (dd == 0) //���̸� ��������
	{
		nextx = startx + direct3[0];
		nexty = starty + direct3[1];
		d1 = 3;
		backx = startx + direct2[0];  //��������
		backy = starty + direct2[1];
	}
	else if (dd == 1) //�����̸� ��������
	{
		nextx = startx + direct0[0];
		nexty = starty + direct0[1];
		d1 = 0;
		backx = startx + direct3[0];  //��������
		backy = starty + direct3[1];
	}
	else if (dd == 2) //�����̸� ��������
	{
		nextx = startx + direct1[0];
		nexty = starty + direct1[1];
		d1 = 1;
		backx = startx + direct0[0];  //��������
		backy = starty + direct0[1];
	}
	else if (dd == 3) //�����̸� ��������
	{
		nextx = startx + direct2[0];
		nexty = starty + direct2[1];
		d1 = 2;
		backx = startx + direct1[0];  //��������
		backy = starty + direct1[1];
	}
	visited[startx][starty] = 1;
	Graph[startx][starty] = 2; //û���Ѱ�
	//printf("����ġ: %d %d ������ġ: %d %d ����ġ: %d %d %d\n", startx, starty, nextx, nexty,backx, backy ,count);
	int ax, ay = 0;
	int k = 0;
	for (int i = 0; i < 4; i++) //�������� ��������
	{
		ax = startx + direct[i][0];
		ay = starty + direct[i][1];
		if (Graph[ax][ay] == 2 || Graph[ax][ay] == 1) //���� �ְų�, û�� �߰ų�
		{
			k++;
		}
		
	}
	if (k == 4)
	{
		//printf("%d %d 4������ �� û�ҵǾ��ֽ��ϴ�\n", startx, starty);
	}
	if (k == 4 && Graph[backx][backy] == 2)   //���δ� û�ҵǾ��ִ�
	{
		//printf("����ġ: %d %d ������ġ: %d %d ����ġ: %d %d %d\n", startx, starty, nextx, nexty, backx, backy, count);
		//printf("���δ� û�ҵǾ��־� �����մϴ�.\n");
		DFS(backx, backy, dd, count);
	}
	else if (k == 4 && Graph[backx][backy] == 1) //�������� ���̰�, ���������� 1�� ������ �������
	{
		//printf("������Ѵ�.\n");
		printf("%d\n", count);
		return;
	}
	 else if (visited[nextx][nexty] == 0 && Graph[nextx][nexty] == 0 ) //û���� ������ ����
	{
		//printf("����ġ: %d %d ������ġ: %d %d ����ġ: %d %d %d\n", startx, starty, nextx, nexty,backx, backy ,count);
		//printf("û���� ������ �����մϴ�.\n");
		DFS(nextx, nexty, d1, count + 1);
	}
	else if (Graph[nextx][nexty] != 0) //û���� �����̾���
	{	
		//printf("����ġ: %d %d ������ġ: %d %d ����ġ: %d %d %d\n", startx, starty, nextx, nexty,backx, backy ,count);
		//printf("û���� ������ �������� �ʾ� ������ Ƶ�ϴ�.");
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