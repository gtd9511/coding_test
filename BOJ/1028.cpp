#include <iostream>
#include <algorithm>
using namespace std;

int R, C, ans = 0;
int dpleft[750][750] = {0, };
int dpright[750][750] = {0, };

int main()
{
	cin >> R >> C;
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			char temp;
			cin >> temp;
			if (temp == '0')
			{
				dpleft[i][j] = 0;
				dpright[i][j] = 0;
			}
			else
			{
				dpleft[i][j] = 1;
				dpright[i][j] = 1;
			}
		}
	}

	for(int i = 0; i < R - 1; i++)
	{
		for(int j = 0; j < C; j++)
		{
			if(dpleft[i][j] != 0 && j != 0)
				dpleft[i + 1][j - 1] += dpleft[i][j];
			if(dpright[i][j] != 0 && j != C - 1)
				dpright[i + 1][j + 1] += dpright[i][j];
		}
	}

	// for (int i = 0; i < R; i++)
	// {
	// 	for (int j = 0; j < C; j++)
	// 		cout << dpleft[i][j] << " ";
	// 	cout << endl;
	// }
	// cout << endl;
	// for (int i = 0; i < R; i++)
	// {
	// 	for (int j = 0; j < C; j++)
	// 		cout << dpright[i][j] << " ";
	// 	cout << endl;
	// }
	for (int i = 0; i < R - 1; i++)
	{
		for (int j = 0; j < C; j++)
		{
			if (dpleft[i][j] != 0 && dpright[i][j] != 0)
			{
				ans = 1;
				if (dpleft[i][j] != 1 && dpright[i][j] != 1)
				// {
				// 	int n = min(dpleft[i][j], dpright[i][j]);
				// 	while (n > 1)
				// 	{
				// 		if (dpright[i + n - 1][j - n + 1] >= n && dpleft[i + n - 1][j + n - 1] >= n)
				// 			ans = max(ans, n);
				// 		n--;
				// 	}


				}
			}
		}
	}
	if (ans != 0)
		cout << ans + 1;

	return (0);
}

