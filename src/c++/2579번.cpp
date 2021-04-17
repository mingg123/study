#include <iostream>
#include <algorithm>
using namespace std;

int dp[1001];
int stair[1001];
int N;
void DP()
{
	dp[1] = stair[1];
	dp[2] = stair[2] + stair[1];
	for (int i = 3; i <= N; i++)
	{
		dp[i] = max(stair[i] + stair[i - 1] + dp[i - 3], stair[i]+dp[i-2]);
		//printf("dp´Â : %d\n", dp[i]);
	}
}
int main()
{
	
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		int a;
		cin >> a;
		stair[i] = a;
	}
	DP();
	printf("%d", dp[N]);
}