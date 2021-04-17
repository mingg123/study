#include <iostream>
using namespace std;
int N, M;
int arr[1001];
int visited[1001];
void ans(int m)
{
	if (m == M)
	{
		for (int i = 0; i < M; i++)
		{
			printf("%d ", arr[i]);
		}
		printf("\n");
		return;
	}
	for (int i = 1; i <= N; i++)
	{
		if (visited[i] == 0)
		{
			arr[m] = i;
			visited[i] = 1;
			ans(m + 1);
			visited[i] = 0;
		}
	}
}
int main()
{
	cin >> N >> M;
	ans(0);
}