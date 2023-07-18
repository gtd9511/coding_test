#include <iostream>
using namespace std;

int N;
bool color[100][100];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	int x, y;
	for (int i = 0; i < N; i++)
	{
		cin >> x >> y;
		for (int j = x - 1; j < x + 9; j++)
		{
			for (int k = y - 1; k < y + 9; k++)
				color[j][k] = true;
		}
	}
	int ans = 0;
	for (int i = 0; i < 100; i++)
	{
		for (int j = 0; j < 100; j++)
		{
			if (color[i][j])
				ans++;
		}
	}
	cout << ans;
	return (0);
}
