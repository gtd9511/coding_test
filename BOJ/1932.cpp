#include <iostream>
#include <algorithm>
using namespace std;

int n, dp[500][500] = {0, }, ans = 0;
int main()
{
	cin >> n;
	if (n == 1)
	{
		cin >> dp[0][0];
		cout << dp[0][0];
		return (0);
	}
	for (int i = 0;i < n; i++)
		for (int j = 0; j < i + 1; j++)
			cin >> dp[i][j];

	for (int i = 1; i < n; i++)
		for (int j = 0; j < i + 1; j++)
		{
			if (j == 0)
				dp[i][j] += dp[i - 1][0];
			else if (i == j)
				dp[i][j] += dp[i - 1][j - 1];
			else
				dp[i][j] += max(dp[i - 1][j - 1], dp[i - 1][j]);
			if (ans < dp[i][j])
				ans = dp[i][j];
		}
	cout << ans;
	return (0);
}
