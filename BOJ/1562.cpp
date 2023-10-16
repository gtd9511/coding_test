#include <iostream>
#include <string.h>
using namespace std;

int N, dp[101][10][1 << 10], ans = 0;

int main()
{
	memset(dp, 0, sizeof(dp));
	cin >> N;
	if (N < 10)
	{
		cout << 0;
		return (0);
	}
	for (int i = 1 ; i < 10; i++)
		dp[1][i][1 << i] = 1;

	for (int i = 1; i < N + 1; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			for (int k = 0; k < 1024; k++)
			{
				if (j == 0)
					dp[i][j][k | (1 << j)] += dp[i - 1][1][k];
				else if (j == 9)
					dp[i][j][k | (1 << j)] += dp[i - 1][8][k];
				else
					dp[i][j][k | (1 << j)] += dp[i - 1][j - 1][k] + dp[i - 1][j + 1][k];
				dp[i][j][k] %= 1000000000;
			}
		}
	}

	for (int i = 0; i < 10; i++)
	{
		ans += dp[N][i][1023];
		ans %= 1000000000;
	}

	cout << ans;

	return (0);
}

//	1	0
//	2
//	3
//	10	9876543210

//	11	89876543210
//		98765432101
//		10123456789

//	12	989876543210
// 		789876543210
//		898765432101
//		987654321010
//		987654321012

//		987876543210


//		9 8 7 6 5 4 3 2 1 0
//		0 1 2 3 4 5 6 7 8 9

//		10	2	1	1
//		11	4	1	3
//		12

