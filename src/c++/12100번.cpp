#include <iostream>
#include <stdio.h>
using namespace std;
int N;
int Graph[20][20];

int result = 0;

void DFS(int Graph[20][20], int count)
{
	if (count == 5)
		return;

	int up[20][20];
	int down[20][20];
	int right[20][20];
	int left[20][20];
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			up[i][j] = Graph[i][j];
			down[i][j] = Graph[i][j];
			right[i][j] = Graph[i][j];
			left[i][j] = Graph[i][j];
		}
	}
	int row;
	for (int j = 0; j < N; j++)
	{
		row = 0;
		for (int i = 1; i < N; i++)
		{
			if (up[i][j] != 0)
			{
				if (up[row][j] == 0)
				{
					up[row][j] = up[i][j];
					up[i][j] = 0;
				}
				else if (up[i][j] == up[row][j])
				{
					up[row][j] = 2 * up[i][j];
					up[i][j] = 0;
					if (result < up[row][j])
					{
						result = up[row][j];
					}
					row++;
				}
				else if (up[i][j] != up[row][j])
				{
					row++;
					up[row][j] = up[i][j];
					if (row != i)
					{
						up[i][j] = 0;
					}
				}
			}
			
		}
	}
	DFS(up, count + 1);
	int col;
	for (int j=0; j<N; j++)
	{
		col = N - 1;
		for (int i = N - 2; i >= 0; i--)
		{
			if (down[i][j] != 0)
			{
				if (down[col][j] == 0)
				{
					down[col][j] = down[i][j];
					down[i][j] = 0;
				}
				else if (down[col][j] == down[i][j])
				{
					down[col][j] = 2 * down[i][j];
					down[i][j] = 0;
					if (result < down[col][j])
					{
						result = down[col][j];
					}
					col--;
				}
				else if (down[col][j] != down[i][j])
				{
					col--;
					down[col][j] = down[i][j];
					if (col != i)
					{
						down[i][j] = 0;
					}
				}
			}
		}
	}
	DFS(down, count + 1);

	for (int i = 0; i < N; i++)
	{
		col = 0;
		for (int j = 1; j < N; j++)
		{
			if (right[i][j] != 0)
			{
				if (right[i][col] == 0)
				{
					right[i][col] = right[i][j];
					right[i][j] = 0;
				}
				else if (right[i][col] == right[i][j])
				{
					right[i][col] = 2 * right[i][j];
					col++;
					right[i][j] = 0;
					if (result < right[i][col])
					{
					result = right[i][col];
					}
				}
				else if (right[i][col] != right[i][j])
				{
					col++;
					right[i][col] = right[i][j];
					if (col != j)
					{
						right[i][j] = 0;
					}
				}
			}
		}
	}
	DFS(right, count + 1);

	for (int i = 0; i< N; i++)
	{
		row = N - 1;
		for (int j = N - 2; j >= 0; j--)
		{
			if (left[i][j] != 0)
			{
				if (left[i][row] == 0)
				{
					left[i][row] = left[i][j];
					left[i][j] = 0;
				}
				else if (left[i][row] == left[i][j])
				{
					left[i][row] = 2 * left[i][j];
					left[i][j] = 0;
					if (result < left[i][row])
					{
						result = left[i][row];
					}
					row--;
					
				}
				else if (left[i][row] != left[i][j])
				{
					row--;
					left[i][row] = left[i][j];
					if (row != j)
						left[i][j] = 0;
				}
			}
		}
	}
	DFS(left, count + 1);

}
int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			int a;
			cin >> a;
			Graph[i][j] = a;
			if (result < Graph[i][j])
				result = Graph[i][j];
		}
	}
	DFS(Graph, 0);
	printf("%d\n", result);
}