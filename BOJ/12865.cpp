#include <iostream>
using namespace std;

int N, K;
int N_weight[101];
int N_value[101];
// int max_value[1000001];
int DP[101][1000001];

int main()
{
	cin >> N >> K;
	for (int i = 1; i < N + 1; i++)
		cin >> N_weight[i] >> N_value[i];

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= K; j++)
		{
			 if (j - N_weight[i] >= 0)
			 	DP[i][j] = max(DP[i - 1][j], DP[i - 1][j - N_weight[i]] + N_value[i]);
			 else
			 	DP[i][j] = DP[i - 1][j];
		}
	}
	cout << DP[N][K];
	return (0);
}
