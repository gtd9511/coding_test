#include <iostream>
using namespace std;

int N, M;
int arr[1025][1025] = {0, };

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			cin >> arr[i][j];
			arr[i][j] += arr[i][j - 1] + arr[i - 1][j] - arr[i - 1][j - 1];
		}
	}

	for (int i = 0; i < M; i++)
	{
		int x1, y1, x2, y2, ans = 0;
		cin >> x1 >> y1 >> x2 >> y2;
		ans = arr[x2][y2] - arr[x2][y1 - 1] - arr[x1 - 1][y2] + arr[x1 - 1][y1 - 1];
		cout << ans << "\n";
	}
	return (0);
}
