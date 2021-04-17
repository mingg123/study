#include <iostream>
#include <queue>
using namespace std;

struct tomato {
	int x, y, z;
};
int Graph[101][101][101];
int Graph2[101][101][101];
int visited[101][101][101];
int direct[6][3] = { {0,1,0}, {0,-1,0}, {0,0,-1}, {0,0,1},{-1,0,0},{1,0,0} };
int M, N, H;
queue <tomato> q;
void BFS()
{
	while (!q.empty())
	{
		int startx = q.front().x;
		int starty = q.front().y;
		int startz = q.front().z;
		q.pop();
		for (int i = 0; i < 6; i++)
		{
			int nextx = startx + direct[i][0];
			int nexty = starty + direct[i][1];
			int nextz = startz + direct[i][2];
			if (nextx >= 1 && nextx <= N && nexty >= 1 && nexty <= M && nextz >= 1 && nextz <= H && Graph[nextx][nexty][nextz] == 0 && Graph[nextx][nexty][nextz]!=-1 && visited[nextx][nexty][nextz]==0)
			{
			
					q.push({ nextx, nexty, nextz });
					visited[nextx][nexty][nextz] = 1;
					Graph[nextx][nexty][nextz] = Graph[startx][starty][startz] + 1;
			}

				
		}
	}

	
for (int i = 1; i <= H; i++)
{
	for (int j = 1; j <= N; j++)
	{
		for (int k = 1; k <= M; k++)
		{
			printf("%d ", Graph[j][k][i]);
		}printf("\n");
	}printf("\n");

}printf("\n");

	int max = 0;
	for (int i = 1; i <= H; i++)
	{
		max = Graph[1][1][1];
		for (int j = 1; j <= N; j++)
		{
			for (int k = 1; k <= M; k++)
			{
				
				if (Graph[j][k][i] == 0)
				{
					printf("-1\n");
					return;
				}
				if (max < Graph[j][k][i])
				{
					max = Graph[j][k][i];
				}
			}
		}
	}
	printf("%d\n", max - 1);
}
int main()
{
	cin >> M >> N >> H;
	int cnt = 0;
	for (int i = 1; i <= H; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			for (int k = 1; k <= M; k++)
			{
				int a;
				cin >> a;
				Graph[j][k][i] = a;
				Graph2[j][k][i] = Graph[j][k][i];
				if (Graph[j][k][i] == 0)
				{
					cnt++;
				}
			}
		}
	}
	if (cnt == 0)
	{
		printf("0\n");
		return 0;
	}
	for (int i = 1; i <= H; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			for (int k = 1; k <= M; k++)
			{
				if (Graph[j][k][i] == 1)
				{
					q.push({ j,k,i });
					//visited[j][k][i] = 1;
				}
				
			}
		}

	}
	BFS();
	

	
}