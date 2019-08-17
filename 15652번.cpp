#include <iostream>
using namespace std;

int N, M;
int arr[9];
void ans(int m)
{
	if (m == M)
	{
		for (int i = 0; i < M; i++)
		{
			cout << arr[i] << " ";
		}
		cout << endl;
		return;
	}
	if (m == 0)
	{
		for (int i = 1; i <= N; i++)
		{
			arr[m] = i;
			ans(m + 1);
		}
	}
	else {


		for (int i = arr[m - 1]; i <= N; i++)
		{
			arr[m] = i;
			ans(m + 1);
		}
	}
}
int main()
{
	cin >> N >> M;
	ans(0);
}