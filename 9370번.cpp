#include <stdio.h>
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
int T;
int n, m, t;
int s, g, h;
int tnum[101];
priority_queue <pair<int, int>, vector <pair <int, int>>, greater <pair<int, int>>> pq;
vector <pair <int, int>> map[2001];
int Graph[2001];
int result[2001];
int result1[2001];
int result2[2001];
int realresult[2001];

void init() {
	for (int i = 0; i < m; i++)
	{
		result[i] = 0;
		result1[i] = 0;
		result2[i] = 0;
		realresult[i] = 0;
	}


}
int ans(int start, int end)
{
	for (int i = 1; i <= n; i++)
	{
		Graph[i] = 9999;
	}
	Graph[start] = 0;
	pq.push({ 0,start });
	while (!pq.empty())
	{
		int start = pq.top().second;
		int weight = pq.top().first;
		pq.pop();
		for (int i = 0; i < map[start].size(); i++)
		{
			int next = map[start][i].first;
			int weight2 = weight + map[start][i].second;
			if (Graph[next] > weight2)
			{
				Graph[next] = weight2;
				pq.push({ weight2, next });
			}
		}
	}
	/*for (int i = 1; i <= n; i++)
	{
		printf("%d ", Graph[i]);
	}
	*/
	return Graph[end];
}
int main()
{
	scanf_s("%d", &T);
	for (int i = 0; i < T; i++)
	{
		init();
	
		scanf_s("%d %d %d ", &n, &m, &t);
		scanf_s("%d %d %d", &s, &g, &h);
		
		for (int i = 0; i < m; i++)
		{
			int a, b, d;
			scanf_s("%d %d %d", &a, &b, &d);
			map[a].push_back({ b,d });
			map[b].push_back({ a,d });
		}
		
		for (int i = 0; i < t; i++)
		{
			int x;
			scanf_s("%d", &x);
			result[i] = ans(s, x);
			int ans1 = ans(s, g);
			int ans2 = ans(g, h);
			int ans3 = ans(h, x);
			result1[i] = ans1 + ans2 + ans3;

			int ans4 = ans(s, h);
			int ans5 = ans(h, g);
			int ans6 = ans(g, x);
			result2[i] = ans4 + ans5 + ans6;

			int minum = min(result1[i], result2[i]);
			//printf("minnum: %d\n", minum);
			//printf("result[i]: %d\n", result[i]);
			if (result[i] >= minum) //무조건 거치면
			{
				realresult[i] = x;
			}
			
		}
		sort(realresult, realresult + t);
		for (int i = 0; i < t; i++)
		{
			if (realresult[i] != 0)
				printf("%d ", realresult[i]);
			
		}
		for (int i = 1; i <= n; i++)
		{
			map[i].clear();
		}
		printf("\n");
	}
}