#include <iostream>
#include <vector>
using namespace std;
struct inf {
	int x, y, d,state,g;
};
vector <inf> v;
int direct[4][2] = { {1,0},{0,-1},{-1,0},{0,1} };  // 0 , 1 , 2 , 3 ,순서
int N,x, y, d, g;
int Graph[101][101];
int cnt;
void find()
{
	cnt = 0;
	for (int i = 0; i < 101; i++)
	{
		for (int j = 0; j < 101; j++)
		{
			int startx = i;
			int starty = j;
			int nextx1 = 0; int nexty1 = 0; int nextx2 = 0; int nexty2 = 0; int nextx3 = 0; int nexty3 = 0;
			if (Graph[startx][starty] == 1)
			{
				nextx1 = startx + direct[3][0];
				nexty1 = starty + direct[3][1];
				if (Graph[nextx1][nexty1] == 1 && nextx1 <=100 && nexty1 <=100)
				{
					nextx2 = nextx1 + direct[0][0];
					nexty2 = nexty1 + direct[0][1];
					if (Graph[nextx2][nexty2] == 1 && nextx2<=100 && nexty2<=100)
					{
						nextx3 = nextx2 + direct[1][0];
						nexty3 = nexty2 + direct[1][1];
						if (Graph[nextx3][nexty3] == 1 && nextx1>=0 && nexty1>=0)
						{
							cnt++;
							//printf("%d %d %d %d %d %d %d %d \n", startx, starty, nextx1, nexty1, nextx2, nexty2, nextx3, nexty3);
						}
					}
				}
			}
		}
	}
}
void clear()
{
	while (!v.empty())
	{
		v.pop_back();
	}
}
void ans(int count)  //넣는것
{

	while (g!=v.back().state)
	{
		int n = v.back().state+1;
		for (int i = v.size() - 1; i >= 0; i--)
		{
			int x = v[i].x;
			int y = v[i].y;
			int d = v[i].d;
			int state = v[i].state;
			int g = v[i].g;
		
			if (d == 0)
			{
				int nextx = v[v.size() - 1].x + direct[1][0];
				int nexty = v[v.size() - 1].y + direct[1][1];
				if (nextx > 100 || nexty > 100)
					continue;
				d = 1;
				v.push_back({ nextx, nexty, d, n,g });
				Graph[nexty][nextx] = 1;
			}
			else if (d == 1)
			{
				int nextx = v[v.size() - 1].x + direct[2][0];
				int nexty = v[v.size() - 1].y + direct[2][1];
				if (nextx > 100 || nexty > 100)
					continue;
				d = 2;
				v.push_back({ nextx, nexty, d, n,g });
				Graph[nexty][nextx] = 1;
			}
			else if (d == 2)
			{
				int nextx = v[v.size() - 1].x + direct[3][0];
				int nexty = v[v.size() - 1].y + direct[3][1];
				if (nextx > 100 || nexty > 100)
					continue;
				d = 3;
				v.push_back({ nextx, nexty, d, n,g });
				Graph[nexty][nextx] = 1;
			}
			else if (d == 3)
			{
				int nextx = v[v.size() - 1].x + direct[0][0];
				int nexty = v[v.size() - 1].y + direct[0][1];
				if (nextx > 100 || nexty > 100)
					continue;
				d = 0;
				v.push_back({ nextx, nexty, d, n,g });
				Graph[nexty][nextx] = 1;
			}
		}
		for (int i = 0; i < v.size(); i++)
		{
			//printf("v값은: %d %d %d %d %d\n", v[i].x, v[i].y, v[i].d, v[i].state, v[i].g);
		}
		//printf("------------------------------------\n");
	}
	
	
}
void init(int x , int y, int d, int g)
{
	int nextx = 0; int  nexty = 0;
	if (d == 0) //방향이면
	{
		nextx = x + direct[0][0];
		nexty = y + direct[0][1];
		
	}
	else if (d == 1)
	{
	nextx = x + direct[1][0];
		 nexty = y + direct[1][1];
	}
	else if (d == 2)
	{
		nextx = x + direct[2][0];
		nexty = y + direct[2][1];
	}
	else if (d == 3)
	{
		nextx = x + direct[3][0];
		nexty = y + direct[3][1];
	}
	v.push_back({ nextx, nexty, d, 0, g });
	Graph[nexty][nextx] = 1;
	//printf(" next v는 : %d %d %d %d %d\n", v[0].x, v[0].y, v[0].d, v[0].state, v[0].g);
	//printf("%d\n", v.size());
	ans(0);
}
int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> x >> y >> d >> g;
		Graph[y][x] = 1;
		clear();
		init(x,y,d,g);
	}
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			//printf("%d ", Graph[i][j]);
		}
		//printf("\n");
	}
	find();
	printf("%d", cnt);
}