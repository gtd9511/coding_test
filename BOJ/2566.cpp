#include <iostream>
using namespace std;

int arr[9][9];

int main()
{
	int max = -1;
	int x, y;
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			cin >> arr[i][j];
			if (max < arr[i][j])
			{
				max = arr[i][j];
				x = i + 1;
				y = j + 1;
			}
		}
	}
	cout << max << '\n' << x << ' ' << y;
	return (0);
}
