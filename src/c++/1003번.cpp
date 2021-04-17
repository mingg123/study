#include <iostream>
using namespace std;
/// 시간초과가 남으로 DP로 풀어야 합니다.
int zerocount[1001];  //0의 횟수를 저장할 배열
int onecount[1001];  //1의 횟수를 저장할 배열
void DP(int n)
{
	zerocount[0] = 1;  //0일때의 0횟수와 1횟수를 각각 저장해줍니다.
	onecount[0] = 0;
	zerocount[1] = 0; //1일때의 0횟수와 1횟수를 저장해줍니다.
	onecount[1] = 1;
	for (int i = 2; i <= n; i++)
	{
		zerocount[i] = zerocount[i - 1] + zerocount[i - 2];
		onecount[i] = onecount[i - 1] + onecount[i - 2];
	}
}
int main()
{
	int N;
	cin >> N;
	DP(40);
	for (int i = 0; i < N; i++)
	{
		int num;
		cin >> num;
		printf("%d %d\n", zerocount[num], onecount[num]);
		
	}
}