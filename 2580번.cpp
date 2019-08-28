#include <iostream>
using namespace std;

int Graph[9][9];
int row[9][10];
int col[9][10];
int squar[9][10];
int change(int x, int y)
{
	return (x / 3) * 3 + y / 3;
}
void DFS(int cnt)
{
	if (cnt == 81)
	{
		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 9; j++)
			{
				cout << Graph[i][j] << " ";
			}
			cout << endl;
		}
		return;
	}
	int x = cnt / 9;
	int y = cnt % 9;
	if (Graph[x][y] != 0)
	{
		DFS(cnt + 1);
	}
	else {
		for (int i = 1; i <= 9; i++)
		{
			if (row[x][i] == 0 && col[y][i] == 0 && squar[change(x, y)][i] == 0)
			{
				row[x][i] = 1;
				col[y][i] = 1;
				squar[change(x, y)][i] = 1;
				Graph[x][y] = i;
				DFS(cnt + 1);
				row[x][i] = 0;
				col[y][i] = 0;
				squar[change(x, y)][i] = 0;
			}
		}
	}
}
int main()
{
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			int a;
			cin >> a;
			Graph[i][j] = a;
			if (Graph[i][j] != 0)
			{
				row[i][Graph[i][j]] = 1;
				col[j][Graph[i][j]] = 1;
				squar[change(i, j)][Graph[i][j]] = 1;
			}
		}
	}
	DFS(0);
}