#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int direct[4][2] = { {0,1},{1,0},{0,-1},{-1,0} };
struct cc {
	int type, x, y;
};
vector <cc> v;
int N, M;
int Graph[9][9];
int cctv;
int result = 999;
void move(int, int, int);
void DFS(int);
void copy(int a[9][9], int b[9][9])  //a에 b를 복사
{
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			a[i][j] = b[i][j];
		}
	}
}
void move(int dir, int x, int y)
{
	if (dir == 0) //동
	{
		for (int i = y + 1; i <= M; i++)
		{
			if (Graph[x][i] == 6)
			{
				break;
			}
			if (Graph[x][i] == 0)
			{
				Graph[x][i] = -1; //확인한쪽
			}
		}
	}
	else if (dir == 1) //남
	{
		for (int i = x + 1; i <= N; i++)
		{
			if (Graph[i][y] == 6)
			{
				break;
			}
		
			if(Graph[x][i]==0)
			Graph[i][y] = -1; //확인한쪽
			
		}
	}
	else if (dir == 2) //서
	{
		for (int i = y - 1; i >= 1; i--)
		{
			if (Graph[x][i] == 6)
			{
				break;
			}
			if (Graph[x][i] == 0)
				Graph[x][i] = -1; //확인한쪽
			
		}
	}
	else if (dir == 3) //북
	{
		for (int i = x - 1; i >= 1; i--)
		{
			if (Graph[i][y] == 6)
			{
				break;
			}
			if (Graph[x][i] == 0)
				Graph[i][y] = -1; //확인한쪽
			
		}
	}

}
void DFS(int count)
{

	if (count == cctv)
	{
		int ans = 0;
		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= M; j++)
			{
				if (Graph[i][j] == 0)
				{
					ans++;
				}
			}
		}
		result = min(result, ans);
		return;
	}
	int t = v[count].type;
	int x = v[count].x;
	int y = v[count].y;

	int Graph2[9][9];
	copy(Graph2, Graph); //Graph2에 Graph를 복사
	if (t == 1)  //1번 cctv
	{

		for (int dir = 0; dir < 4; dir++)
		{
			move(dir, x, y);
			DFS(count + 1);
			copy(Graph, Graph2);
		
		}
	}
	else if (t == 2)
	{
		for (int dir = 0; dir < 2; dir++)
		{
			move(dir, x, y); //dir=0서, dir1=남
			move(dir + 2, x, y); //dir=0동 dir=1북
			DFS(count + 1);
			copy(Graph, Graph2);

		}
	}
	else if (t == 3)
	{

		for (int dir = 0; dir < 4; dir++)
		{
			
			move(dir, x, y);
			move((dir + 1)%4, x, y);  //dir=3이면 0
			
			DFS(count + 1);
			copy(Graph, Graph2);

		}

	}
	else if (t == 4)
	{

		for (int dir = 0; dir < 4; dir++)
		{
				move((dir%4), x, y);   //2면 2,3,0  3이면 3 0 1
				move((dir + 1)%4, x, y);
				move((dir + 2)%4, x, y);
			
		
			DFS(count + 1);
			copy(Graph, Graph2);

		}
	}
	else if (t == 5)
	{
		move(0, x, y);
		move(1, x, y);
		move(2, x, y);
		move(3, x, y);
		DFS(count + 1);
		copy(Graph, Graph2);

	}


}
int main()
{
	cin >> N >> M;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			int a;
			cin >> a;
			Graph[i][j] = a;
		}
	}
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			if (Graph[i][j] != 0 && Graph[i][j] != 6)
			{
				cctv++;
				v.push_back({ Graph[i][j], i,j });
			}
		}
	}
	//printf("vector: \n");
	for (int i = 0; i < cctv; i++)
	{
		//printf("%d %d %d", v[i].type, v[i].x, v[i].y);
	}

	DFS(0);
	printf("%d ", result);
}