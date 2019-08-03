#include <iostream>
#include <queue>
using namespace std;
struct ans {
	int x, y, count;
};
int visited[200001];
int N, K;
void BFS(int n, int k, int count)
{
	queue <ans> q;
	q.push({ n,k,0 });
	visited[n] = 1;
	while (!q.empty())
	{
		int startx = q.front().x;
		int starty = q.front().y;
		int cnt = q.front().count;
		//printf("startx :%d %d %d \n", startx, starty, cnt);
		if (startx == starty)
		{
			printf("%d\n", cnt);
			return;
		}
		q.pop();
		int nextx1 = startx + 1;
		int nextx2 = startx - 1;
		int nextx3 = startx * 2;
		
		if (visited[nextx1] == 0 && nextx1 >=0)
		{
			q.push({ nextx1,starty, cnt + 1 });
			visited[nextx1] = 1;
			//printf("nextx1 :%d %d %d \n", nextx1, starty, cnt+1);
		}
		if (visited[nextx2] == 0 && nextx2>=0)
		{
			q.push({ nextx2,starty, cnt + 1 });
			visited[nextx2] = 1;
			//printf("nexty2 :%d %d %d \n", nextx2, starty, cnt+1);
		}
		if (nextx3-starty<=starty-startx&&visited[nextx3] == 0&& nextx3 >=0)
		{
			q.push({ nextx3,starty, cnt + 1 });
			visited[nextx3] = 1;
			//printf("nextx3 :%d %d %d \n", nextx3, starty, cnt+1);
		}
	}

}
int main()
{
	cin >> N >> K;
	BFS(N, K,0);
}