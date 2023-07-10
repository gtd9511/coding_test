re
#include <iostream>
//#include <algorithm>

using namespace std;

int main ()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int N;
	int ans = 0;
	int T[16] = {0};
	int P[16] = {0};
	int dp[16] = {0};
	cin >> N;
	for (int i = 1; i < N + 1; i++)
	{
		cin >> T[i] >> P[i];
		for (int j = 0; j < i; j++)
		{
			if (T[j] + j <= i && i+ T[i] <= N + 1)
				dp[i] = max(dp[i], dp[j] + P[i]);
		}
	}
	for (int i = 0; i < N + 1; i++)
	{
		ans = max(ans, dp[i]);
	}
	cout << ans << endl;
	return (0);
}
