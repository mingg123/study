#include <iostream>
#include <vector>
using namespace std;
int TC, N, M, W;
vector <pair <int, int>> map[501];
int Graph[501];
int flag;
void ans()
{
	flag = 0;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			for (int k = 0; k < map[j].size(); k++)
			{
				int next = Graph[j] + map[j][k].second;
				if (Graph[j] != 999999999 && Graph[map[j][k].first]> next)
				{
					Graph[map[j][k].first] = next;
					flag = 1;
				}
			}
		}
	}
}
void init()
{
	for (int i = 1; i <= N; i++)
	{
		Graph[i] = 999999999;
	}
	Graph[1] = 0;
}
int main()
{
	cin >> TC;
	for (int i = 0; i < TC; i++)
	{
		cin >> N >> M >> W;
		int s, e, t;
		for (int i = 0; i < M; i++)
		{
			cin >> s >> e >> t;
			map[s].push_back({ e,t });
			map[e].push_back({ s,t });
		}
		for (int i = 0; i < W; i++)
		{
			cin >> s >> e >> t;
			map[s].push_back({ e,-t });
		}
		init();
		ans();
		ans();
		if (flag == 1)
		{
			cout << "YES" << endl;
		}
		else
		{
			cout << "NO" << endl;
		}
		for (int i = 1; i <=N; i++)
		{
			map[i].clear();
		}
	
	}
	return 0;
}
