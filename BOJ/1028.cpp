#include <iostream>
#include <algorithm>
using namespace std;

int R, C, ans = 0;
long long dpleft[750][750] = {0, };
long long dpright[750][750] = {0, };

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

	for(int i = 1; i < R; i++)
	{
		for(int j = 0; j < C; j++)
		{
			if(dpleft[i][j] == 1 && j != C - 1)
				dpleft[i][j] += dpleft[i - 1][j + 1];
			if(dpright[i][j] == 1 && j != 0)
				dpright[i][j] += dpright[i - 1][j - 1];
		}
	}

	// for(int i = 0; i < R; i++)
	// {
	// 	for(int j = 0; j < C; j++)
	// 		cout << dpleft[i][j] << " ";
	// 	cout << endl;
	// }
	// cout << endl;
	// for(int i = 0; i < R; i++)
	// {
	// 	for(int j = 0; j < C; j++)
	// 		cout << dpright[i][j] << " ";
	// 	cout << endl;
	// }

	for (int i = R - 1; i >= 0; i--)
	{
		for (int j = C - 1; j >= 0; j--)
		{
			if (dpleft[i][j] != 0 && dpright[i][j] != 0)
			{
				ans = max(ans, 1);
				if (dpleft[i][j] != 1 && dpright[i][j] != 1)
				{
					int n = min(dpleft[i][j], dpright[i][j]);
					while (n > 1)
					{
						if (dpright[i - n + 1][j + n - 1] >= n && dpleft[i - n + 1][j - n + 1] >= n)
							ans = max(ans, n);
						n--;
					}
				}
			}
		}
	}
	cout << ans;
	return (0);
}

