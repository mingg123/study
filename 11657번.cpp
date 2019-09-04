#include <iostream>
#include <vector>

using namespace std;
vector <pair <int, int>> map[501];
int N, M;
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
				if (Graph[j]!=999999999 && Graph[map[j][k].first] > next)
				{
					Graph[map[j][k].first] = next;
					flag = 1;
					
				}

			}
		}
	}
}
int main()
{
	cin >> N >> M;
	for (int i = 0; i < M; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		map[a].push_back({ b,c });
	}
	for (int i = 1; i <= N; i++)
	{
		Graph[i] = 999999999;
	}
	Graph[1] = 0;
	ans();
	ans();
	if (flag==1)
	{
		cout << "-1" << endl;
	}
	else {
		for (int i = 2; i <= N; i++)
		{
			if (Graph[i] == 999999999)
			{
				cout << "-1" << endl;
			}
			else {
				cout << Graph[i] << endl;
			}
		}
	}
}