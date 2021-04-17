#include <iostream>
#include <algorithm>
using namespace std;
int d[1000001];
void DP(int N)
{
	d[1] = 0;
	d[2] = 1;
	d[3] = 1;
	for (int i = 4; i <= N; i++)
	{
		d[i] = d[i - 1] + 1;
		if (i % 3 == 0)
		{
			d[i]=min(d[i], d[i / 3] + 1);
		}
		if (i % 2 == 0)
		{
			d[i]=min(d[i], d[i / 2] + 1);
		}
		//printf("%d %d\n", i, d[i]);
	}
}
int main()
{
	int N;
	cin >> N;
	DP(N);
	printf("%d", d[N]);
}