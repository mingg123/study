#include <iostream>
int arr[1001];
using namespace std;
int N, M;
void ans(int m)
{
	if (m == M)
	{
		for (int i = 0; i < M; i++)
		{
			printf("%d ",arr[i]);
		}
		printf("\n");
		return;
	}
	for (int i = 1; i <= N; i++)
	{
		arr[m] = i;
		ans(m + 1);
	}

}
int main()
{
	cin >> N >> M;
	ans(0);
}