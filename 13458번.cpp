#include <iostream>
using namespace std;
long test[1000001];
long king1num[1000001]; //�Ѱ����� �ִ� ��
long king2num[1000001]; //�ΰ����� �ִ� ��
long num;
int king1, king2;

void testroom(int king1, int king2)
{
	long second;
	for (int i = 0; i < num; i++)
	{
		second = test[i] - king1num[i] * king1;
		//printf("%d ��° �ʿ��� �ΰ������� : %d\n", i, second);
		if (second <= 0)
			continue;
		if (second > 0) {
			if (second % king2 == 0)
			{
				king2num[i] = second / king2;
			}
			else {
				king2num[i] = (second / king2) + 1;
			}
			//printf("%d ��° �ʿ��� �ΰ������� : %d\n", i, king2num[i]);
		}
	}
}
int main()
{
	cin >> num;
	for (int i = 0; i < num; i++)
	{
		int a;
		cin >> a;
		test[i] = a;
		king1num[i] = 1;
	}
	cin >> king1 >> king2;
	testroom(king1, king2);
	long result = 0;
	for (int i = 0; i < num; i++)
	{
		result = result + king1num[i] + king2num[i];
		//printf("%d ��° �������� : %d\n", i, king1num[i]);
		//printf("%d ��° �ΰ������� : %d\n", i, king2num[i]);
	}
	printf("%d", result);
}