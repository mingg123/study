#include <iostream>
#include <queue>
using namespace std;
int N, M;
int Graph[101][101];
int visitied[101][101][5];
int direct[5][2] = { {0,0},{0,1},{0,-1},{1,0},{-1,0} };
int sx, sy, dir1;
int nx, ny, dir2;
struct robot {
	int x, y, dir, cnt;
};
void BFS()
{
	queue <robot> q;
	q.push({ sx, sy, dir1, 0 });
	visitied[sx][sy][dir1] = 1;
	while (!q.empty())
	{
		int x = q.front().x;
		int y = q.front().y;
		int dir = q.front().dir;
		int cnt = q.front().cnt;
		q.pop();
		//cout << "BFSµµÂø" << endl;
		if (x == nx && y == ny && dir == dir2)
		{
			cout << cnt << endl;
			return;
		}
		for (int i = 1; i <= 3; i++)
		{
			int nextx = x + direct[dir][0] * i;
			int nexty = y + direct[dir][1] * i;
			if (visitied[nextx][nexty][dir] == 1)
				continue;
			if (nextx >= 1 && nexty >= 1 && nextx <= N && nexty <= M && Graph[nextx][nexty]== 0)
			{
				visitied[nextx][nexty][dir] = 1;
				q.push({ nextx, nexty, dir, cnt + 1 });
			}
			else
				break;
		}
		for (int i = 1; i <= 4; i++)
		{
			if (visitied[x][y][i] == 1)
				continue;
			if ((i == 1 && dir == 2) || (i == 2 && dir == 1) || (i == 3 && dir == 4) || (i == 4 && dir == 3))
			{
				visitied[x][y][i] = 1;
				q.push({ x,y,i, cnt + 2 });
			}
			else {
				visitied[x][y][i] = 1;
				q.push({ x,y,i,cnt + 1 });
			}
		}
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
	cin >> sx >> sy >> dir1;
	cin >> nx >> ny >> dir2;
	BFS();
}