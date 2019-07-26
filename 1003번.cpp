#include <iostream>
using namespace std;
/// �ð��ʰ��� ������ DP�� Ǯ��� �մϴ�.
int zerocount[1001];  //0�� Ƚ���� ������ �迭
int onecount[1001];  //1�� Ƚ���� ������ �迭
void DP(int n)
{
	zerocount[0] = 1;  //0�϶��� 0Ƚ���� 1Ƚ���� ���� �������ݴϴ�.
	onecount[0] = 0;
	zerocount[1] = 0; //1�϶��� 0Ƚ���� 1Ƚ���� �������ݴϴ�.
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