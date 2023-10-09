#include <iostream>
#include <string.h>
using namespace std;

int N , dp[101][10], ans = 0;

int main()
{
	cin >> N;

	memset(dp, 0, sizeof(dp));

	for (int i = 1; i < 10; i++)
		dp[1][i] = 1;

	for (int i = 2; i < N + 1; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (j == 0)
				dp[i][j] = dp[i - 1][1];
			else if (j == 9)
				dp[i][j] = dp[i - 1][8];
			else
				dp[i][j] = dp[i - 1][j - 1] + dp[i -1][j + 1];
			dp[i][j] %= 1000000000;
		}
	}
	for (int i = 0; i < 10; i++)
	{
		ans += dp[N][i];
		ans %= 1000000000;
	}
	cout << ans;
	return (0);
}
