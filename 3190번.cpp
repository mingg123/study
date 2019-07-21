#include <iostream>
#include <stdio.h>
#include <deque>
using namespace std;
int N;
int Graph[1001][1001];
int visited[1001][1001];
char bam[1001];
int direct1[2] = { -1,0 }; //��
int direct2[2] = { 0,1 }; //������
int direct3[2] = { 1,0 }; //�Ʒ�
int direct4[2] = { 0,-1 };  //����

struct point {
	int x,  y;
};
deque <point> snack;
void DFS(int startx, int starty, int d[], int time)
{
	Graph[startx][starty] = 2;
	snack.push_front({ startx, starty });
	if (startx <= 0 || starty <= 0 || startx > N || starty > N)
	{
		cout  << time << endl;
		return;
	}
	
	
	
	if (bam[time] != 0)
	{
		char trans = bam[time];
		if (trans == 'L') //����
		{
			if (d == direct1) //���̸�
			{
				d = direct4;  //��������
			}
			else if (d == direct2) //�������̸�
			{
				d = direct1; // ����
			}
			else if (d == direct3) //�Ʒ��̸�
			{
				d = direct2; //����
			}
			else if (d == direct4) //�����̸�
			{
				d = direct3; //����
			}
		}
		if (trans == 'D') { //�������̸�
			if (d == direct1) //���̸�
			{
				d = direct2;  //��������
			}
			else if (d == direct2) //�������̸�
			{
				d = direct3; // ����
			}
			else if (d == direct3) //�Ʒ��̸�
			{
				d = direct4; //����
			}
			else if (d == direct4) //�����̸�
			{
				d = direct1; //����
			}
		}
	}

	
	int nextx = startx + d[0];
	int nexty = starty + d[1];
	
	//cout << nextx << " " << nexty << endl;

	
	if (Graph[nextx][nexty] == 2)
	{
		printf("%d", time+1);
		return;
	}
	if (Graph[nextx][nexty] == 0) //����� ������
	{
		Graph[snack.back().x][snack.back().y] = 0;
		snack.pop_back();
	}
	//printf("---------------------------\n");
	

	DFS(nextx, nexty, d, time + 1);

}
int main()
{
	int a, b;
	cin >> N;
	cin >> a;
	for (int i = 0; i < a; i++)
	{
		int x, y;
		cin >> x >> y;
		Graph[x][y] = 1; //����ִ� ��ġ
	}
	
	
	cin >> b;

	for (int i = 0; i < b; i++)
	{
		int t;
		char direct;
		cin >> t;
		cin >> direct;
		bam[t] = direct;
	}

	/*for (int i = 0; i < 20; i++)
	{
		printf("%c", bam[i]);
	}
	*/
	//Graph[1][1] = 2;
	DFS(1, 1, direct2, 0);

}