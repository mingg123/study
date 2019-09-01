#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
int N, E, x, y, flag;
vector <pair <int, int>> map[801];
int Graph[801];
int trace[801];
priority_queue <pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
int ans(int startx, int final)
{
	for (int i = 1; i <= N; i++)
	{
		Graph[i] = 9999;
	}

	pq.push({ 0,startx });
	Graph[startx] = 0;
	while (!pq.empty())
	{
		int start = pq.top().second;
		int weight = pq.top().first;
		pq.pop();
		for (int i = 0; i < map[start].size(); i++)
		{
			int nextx = map[start][i].first;
			int weight2 = map[start][i].second + weight;

		  if (Graph[nextx] > weight2)
			{
			Graph[nextx] = weight2;
			pq.push({ weight2, nextx });
			}
		}
	}
	//cout << Graph[final] << endl;
	return Graph[final];
}
int main()
{
	scanf_s("%d %d", &N, &E);

	for (int i = 0; i < E; i++)
	{
		int a, b, c;
		scanf_s("%d %d %d", &a, &b, &c);
		map[a].push_back({ b,c });
		map[b].push_back({ a,c });
	}
	scanf_s("%d %d", &x, &y);
	int trac1 = ans(1, x);
	int trac2 = ans(x, y);
	int trac3 = ans(y, N);
	int result1 = trac1 + trac2 + trac3;


	int trac4 = ans(1, y);
	int trac5 = ans(y, x);
	int trac6 = ans(x, N);
	int result2 = trac4 + trac5 + trac6;
	if (result1 != 9999 && result2 != 9999)
	{
	
	int result = min(result1, result2);
	printf("%d", result);
    }
	else {
		printf("-1\n");
	}
}