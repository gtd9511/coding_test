#include <iostream>

using namespace std;

int arr[15][14] = {0, };

int main()
{
	for (int i = 0; i < 15; i ++)
	{
		for (int j = 0; j < 14; j++)
		{
			if (i == 0)
				arr[i][j] = j + 1;
			else
			{
				for (int k = 0; k < j + 1; k++)
					arr[i][j] += arr[i - 1][k];
			}
		}
	}
	// for (int i = 0; i < 15; i++)
	// {	cout << "[" << i << "] ";
	// 	for (int j = 0; j < 14; j++)
	// 		cout << arr[i][j] << " ";
	// 	cout << endl;
	// }
	int T;
	cin >> T;
	while (T--)
	{
		int k, n;
		cin >> k >> n;
		cout << arr[k][n - 1] << "\n";
	}
	return (0);
}
