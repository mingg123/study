#include <iostream>
#include <queue>
using namespace std;
int N, M;
int arr[1001];
int visited[1001];
int visited2[1001];
void ans(int cnt)
{
	if (cnt == M)
	{
		for (int i = 0; i < M; i++)
		{
			printf("%d ", arr[i]);
		}
		printf("\n");
		return;
	}
	if (cnt == 0)
	{
		for (int i = 1; i <= N; i++)
		{
			if (visited[i] == 0)
			{
				arr[cnt] = i;
				visited[i] = 1;
				ans(cnt + 1);
				visited[i] = 0;

			}

		}
	}
	if (cnt > 0)
	{
		for (int i = arr[cnt - 1]+1; i <= N; i++) // arr[0] 이 1이면 arr[1] 은 2부터 넣어줌 ex) arr[0]=3이면 arr[1]=4가 되는것
		{
			if (visited[i] == 0)
			{
				arr[cnt] = i;
				visited[i] = 1;
				ans(cnt + 1);
				visited[i] = 0;

			}

		}
	}
}
int main()
{
	cin >> N >> M;

	ans(0);
}