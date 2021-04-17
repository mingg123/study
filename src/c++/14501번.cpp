#include <iostream>
#include <algorithm>
using namespace std;
int day[1001];
int money[1001];
int dp[1001];
int N;
void DP()
{
	for (int i = N; i >=1; i--)
	{
		int next = i + day[i];
		if (next > N + 1)
		{
			dp[i] = dp[i + 1];
		}
		else {
			dp[i] = max(dp[i+1], dp[next] + money[i]);
		}
	
	}
}
int main()
{
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		int a, b;
		cin >> a >> b;
		day[i] = a;
		money[i] = b;
	}
	DP();
	printf("%d", dp[1]);
}