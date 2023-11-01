#include <iostream>
#include <string.h>
using namespace std;

long long N, B, M, dp[2][1000001][2][2], ans = 0;

int main()
{
	// ios_base::sync_with_stdio(false);
	// cin.tie(NULL);
	// cout.tie(NULL);
	cin >> N >> B >> M;
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
				dp[i % 2][0][1][1] = dp[1 - (i % 2)][1][0][1] + dp[1 - (i % 2)][1][1][1];
				dp[i % 2][0][1][0] = dp[1 - (i % 2)][1][0][0] + dp[1 - (i % 2)][1][1][0];
			}
			else if (j == B - 1)
			{
				dp[i % 2][B - 1][1][1] = dp[1 - (i % 2)][B - 2][1][0] + dp[1 - (i % 2)][B - 2][1][1];
				dp[i % 2][B - 1][0][1] = dp[1 - (i % 2)][B - 2][0][0] + dp[1 - (i % 2)][B - 2][0][1];
			}
			else
			{
				dp[i % 2][j][0][0] = dp[1 - (i % 2)][j - 1][0][0] + dp[1 - (i % 2)][j + 1][0][0];
				dp[i % 2][j][0][1] = dp[1 - (i % 2)][j - 1][0][1] + dp[1 - (i % 2)][j + 1][0][1];
				dp[i % 2][j][1][0] = dp[1 - (i % 2)][j - 1][1][0] + dp[1 - (i % 2)][j + 1][1][0];
				dp[i % 2][j][1][1] = dp[1 - (i % 2)][j - 1][1][1] + dp[1 - (i % 2)][j + 1][1][1];
			}
			dp[i % 2][j][0][0] %= M;
			dp[i % 2][j][1][0] %= M;
			dp[i % 2][j][0][1] %= M;
			dp[i % 2][j][1][1] %= M;
		}
		// cout << i << "\n";
		// for (int j = 0; j < B; j++)
		// 	cout << dp[i % 2][j][0][0] << " ";
		// cout << endl;
		// for (int j = 0; j < B; j++)
		// 	cout << dp[i % 2][j][1][0] << " ";
		// cout << endl;
		// for (int j = 0; j < B; j++)
		// 	cout << dp[i % 2][j][0][1] << " ";
		// cout << endl;
		// for (int j = 0; j < B; j++)
		// 	cout << dp[i % 2][j][1][1] << " ";
		// cout << endl;
	}
	// for (int j = 0; j < B; j++)
	// 	cout << dp[1 - (N % 2)][j][0][0] << " ";
	// cout << endl;
	// for (int j = 0; j < B; j++)
	// 	cout << dp[1 - (N % 2)][j][1][0] << " ";
	// cout << endl;
	// for (int j = 0; j < B; j++)
	// 	cout << dp[1 - (N % 2)][j][0][1] << " ";
	// cout << endl;
	// for (int j = 0; j < B; j++)
	// 	cout << dp[1 - (N % 2)][j][1][1] << " ";
	// cout << endl;
	// for (int j = 0; j < B; j++)
	// 	cout << dp[N % 2][j][1][1] << " ";
	// cout << endl;


	// cout << endl;
	for (int i = 0; i < B; i++)
	{
		ans += dp[N % 2][i][1][1];
		ans %= M;
	}
	cout << ans;

	return (0);
}













//		2	3	4	5	6	7	8	9
//	1	0	1	2	3	4	5	6	7	8
//	0	1	2	3	4	5	6	7	8	9

//	i	0	>	[i - 1]	1				>	[i - 2]	0 + [i - 2]	2
//	i	1	>	[i - 1]	0 + [i - 1]	2	>	[i - 2]	1 + [i - 2]	1 + [i - 2]	2
//	i	2	>	[i - 1]	1 + [i - 1]	3	>	[i - 2] 0 + [i - 2]	2 + [i - 2]	2 + [i - 2]	4
//	i	3	>	[i - 1]	2 + [i - 1]	4	>	[i - 2]	1 + [i - 2]	3 + [i - 2]	3 + [i - 2]	5
//	i	4	>	[i - 1]	3 + [i - 1]	5	>	[i - 2]	2 + [i - 2]	4 + [i - 2]	4 + [i - 2]	6
//	i	5	>	[i - 1]	4 + [i - 1]	6	>	[i - 2]	3 + [i - 2]	5 + [i - 2]	5 + [i - 2]	7
//	i	6	>	[i - 1]	5 + [i - 1]	7	>	[i - 2]	4 + [i - 2]	6 + [i - 2]	6 + [i - 2]	8
//	i	7	>	[i - 1]	6 + [i - 1]	8	>	[i - 2]	5 + [i - 2]	7 + [i - 2]	7 + [i - 2]	9
//	i	8	>	[i - 1]	7 + [i - 1]	9	>	[i - 2]	6 + [i - 2]	8 + [i - 2]	8
//	i	9	>	[i - 1]	8				>	[i - 2]	7 + [i - 2]	9
