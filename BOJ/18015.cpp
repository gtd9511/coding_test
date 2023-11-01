#include <iostream>
#include <string.h>
using namespace std;

int N, B, dp[2001][2001][2][2], ans = 0;

int main()
{
	cin >> N >> B;
	memset(dp, 0, sizeof(dp));

	if (N < B)
	{
		cout << 0;
		return (0);
	}

	else if (N == B)
	{
		cout << 1;
		return (0);
	}

	for (int i = 1; i < B - 1; i++)
		dp[1][i][0][0] = 1;
	dp[1][B - 1][0][1] = 1;


	for (int i = 2; i <= N; i++)
	{
		for (int j = 0; j < B; j++)
		{
			if (j == 0)
			{
				dp[i][0][1][1] += dp[i - 1][1][0][1] + dp[i - 1][1][1][1];
				dp[i][0][1][0] += dp[i - 1][1][0][0] + dp[i - 1][1][1][0];
			}
			else if (j == B - 1)
			{
				dp[i][B - 1][1][1] += dp[i - 1][B - 2][1][0] + dp[i - 1][B - 2][1][1];
				dp[i][B - 1][0][1] += dp[i - 1][B - 2][0][0] + dp[i - 1][B - 2][0][1];
			}
			else
			{
				dp[i][j][0][0] += dp[i - 1][j - 1][0][0] + dp[i - 1][j + 1][0][0];
				dp[i][j][0][1] += dp[i - 1][j - 1][0][1] + dp[i - 1][j + 1][0][1];
				dp[i][j][1][0] += dp[i - 1][j - 1][1][0] + dp[i - 1][j + 1][1][0];
				dp[i][j][1][1] += dp[i - 1][j - 1][1][1] + dp[i - 1][j + 1][1][1];
			}
			dp[i][j][0][0] %= 1000000000;
			dp[i][j][1][0] %= 1000000000;
			dp[i][j][0][1] %= 1000000000;
			dp[i][j][1][1] %= 1000000000;
		}
		for (int j = 0; j < B; j++)
			cout << dp[i][j][0][0] << " ";
		cout << endl;
		for (int j = 0; j < B; j++)
			cout << dp[i][j][1][0] << " ";
		cout << endl;
		for (int j = 0; j < B; j++)
			cout << dp[i][j][0][1] << " ";
		cout << endl;
		for (int j = 0; j < B; j++)
			cout << dp[i][j][1][1] << " ";
		cout << endl;

	}

	// for (int i = 1; i <= N; i++)
	// {
	// 	for (int j = 0; j < B; j++)
	// 		cout << dp[i][j][0][0] << " ";
	// 	cout << endl;
	// }

	// for (int i = 1; i <= N; i++)
	// {
	// 	for (int j = 0; j < B; j++)
	// 		cout << dp[i][j][1][0] << " ";
	// 	cout << endl;
	// }
	// for (int i = 1; i <= N; i++)
	// {
	// 	for (int j = 0; j < B; j++)
	// 		cout << dp[i][j][0][1] << " ";
	// 	cout << endl;
	// }
	// for (int i = 1; i <= N; i++)
	// {
	// 	for (int j = 0; j < B; j++)
	// 		cout << dp[i][j][1][1] << " ";
	// 	cout << endl;
	// }
	// for (int j = 0; j < B; j++)
	// 	cout << dp[N - 1][j][0][0] << " ";
	// cout << endl;
	// for (int j = 0; j < B; j++)
	// 	cout << dp[N - 1][j][1][0] << " ";
	// cout << endl;
	// for (int j = 0; j < B; j++)
	// 	cout << dp[N - 1][j][0][1] << " ";
	// cout << endl;
	// for (int j = 0; j < B; j++)
	// 	cout << dp[N - 1][j][1][1] << " ";
	// cout << endl;

	for (int i = 0; i < B; i++)
	{
		// if (dp[N][i][1][1])
			// cout << i << " " << dp[N][i][1][1] << endl;
		ans += dp[N][i][1][1];
		ans %= 1000000000;
	}
	cout << ans;

	return (0);
}
