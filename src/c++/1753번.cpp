#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int V, E, K;
int Graph[200002];
priority_queue <pair<int, int>, vector <pair<int, int>>, greater <pair<int,int>>> pq;  //오름차순으로
vector <pair<int, int>>map;
void ans()
{
	pq.push({ K,0 });
	while (!pq.empty())
	{
		int startx = pq.top().first;
		int weight = pq.top().second;
		pq.pop();
		if (Graph[startx] < weight)  //최소거리 임으로
			continue;
		for (int i = 0; i < map[startx].size(); i++)
		{
			int nextx = map[startx][i].first;
			int nextweight = map[startx][i].second+weight;
			if (Graph[nextx] > nextweight)
			{
				Graph[nextx] = nextweight;
				pq.push({ nextx,nextweight });
			}

		}
	}
}
int main()
{
	
	scanf("%d %d %d", &V, &E, &K);
	for (int i = 1; i <= V; i++)
	{
		Graph[i] = 99999;
	}
	map.resize(V + 1);
	for (int i = 0; i < E; i++)
	{
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w);
		map[u].push_back({ v,w });
	}
	Graph[K] = 0;
	ans();
	for (int i = 1; i <= V; i++)
	{
		if (Graph[i] == 99999)
		{
			printf("INF\n");
		}
		else
			printf("%d\n", Graph[i]);
	}
}