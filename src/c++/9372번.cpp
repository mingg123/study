#include <iostream>
#include <queue>
using namespace std;
int T, N, M;
int num[1001];
int Graph[1001][1001];
int visitied[1001];
int main()
{
	cin >> T;
	for (int k = 0; k < T; k++)
	{
		cin >> N >> M;
		for (int i = 0; i < M; i++)
		{
			int a, b;
			cin >> a >> b;
			Graph[a][b] = Graph[b][a] = 1;
		}
		num[k] = N - 1;
	}
	for (int k = 0; k < T; k++)
	{
		cout << num[k] << endl;
	}
}