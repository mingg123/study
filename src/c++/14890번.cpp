#include <iostream>
using namespace std;
int N, L;
int Graph[1001][1001];
void ans()
{
	int cnt, ans = 0;
	int i, j = 0;
	for (i = 1; i <= N * 2; i++) {
		cnt = 1;
		for (j = 1; j <= N - 1; j++) {
			if (Graph[i][j] == Graph[i][j + 1]) cnt++;
			else if (Graph[i][j] + 1 == Graph[i][j + 1] && cnt >= L) cnt = 1;
			else if (Graph[i][j] - 1 == Graph[i][j + 1] &&cnt >= 0) cnt = -L + 1;
			else break;
		}
		if (j == N && cnt >= 0) ans++;
	}
	printf("%d", ans);
}
int main()
{
	cin >> N >> L;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			int num;
			cin >> num;
			Graph[i][j] = num;
		}
	}
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			Graph[i + N][j] = Graph[j][i];
		}
	}
	ans();
	for (int i = 1; i <= 2*N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			//printf("%d", Graph[i][j]);
		}
		//printf("\n");
	}
}