#include <iostream>

using namespace std;

int r1, c1, r2, c2, maxV ,s;
int arr [50][50];

int main()
{
	cin >> r1 >> c1 >> r2 >> c2;

	for (int i = r1; i <= r2; i++)
	{
		for (int j = c1; j <= c2; j++)
		{
			int x = i - r1, y = j - c1;
			if (i - j < 0)
			{
				if (i + j < 0)
					arr[x][y] = 4 * i * i +  i + 1 - j;
				else
					arr[x][y] = 4 * j * j - 3 * j + 1 - i;
			}
			else
			{
				if (i + j < 0)
					arr[x][y] = 4 * j * j - j + 1 + i;
				else
					arr[x][y] = 4 * i * i + 3 * i + 1 + j;
			}
			if (arr[x][y] > maxV)
				maxV = arr[x][y];
		}
	}
	while (maxV)
	{
		maxV /= 10;
		s++;
	}
	for (int i = 0; i <= r2 - r1; i++)
	{
		string str;
		for (int j = 0; j <= c2 - c1; j++)
		{
			str = to_string(arr[i][j]);
			int temp = s - str.length();
			while (temp--)
				cout << " ";
			cout << arr[i][j] << " ";
		}
		cout << "\n";
	}

	return (0);
}
