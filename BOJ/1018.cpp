#include <iostream>
using namespace std;
int N, M;
int arr[50][50];
int ans = 64;

int main()
{
	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		string s;
		cin >> s;
		for (int j = 0; j < M; j++)
			arr[i][j] = s[j];
	}

	for (int i = 0; i < N - 7; i++)
	{
		for (int j = 0; j < M - 7; j++)
		{
			int cnt = 0;
			for (int k = i; k < i + 8; k++)
			{
				for (int l = j; l < j + 8; l++)
				{
					if ((k + l) % 2 == 0)
					{
						if (arr[k][l] == 'B')
							cnt++;
					}
					else
					{
						if (arr[k][l] == 'W')
							cnt++;
					}
				}
			}
			if (cnt > 32)
				cnt = 64 - cnt;
			if (ans > cnt)
				ans = cnt;
		}
	}
	cout << ans << "\n";
	return (0);
}
