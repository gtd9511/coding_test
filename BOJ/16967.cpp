#include <iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int H, W, X, Y;
	cin >> H >> W >> X >> Y;
	int arr[H + X][W + Y];
	int tmp[H][W];
	for (int i = 0; i < H + X; i++)
		for (int j = 0; j < W + Y; j++)
			cin >> arr[i][j];

	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < W; j++)
		{
			tmp[i][j] = arr[i][j];
			if (i >= X && j >= Y)
				tmp[i][j] -= tmp[i - X][j - Y];
		}
	}

	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < W; j++)
		{
			cout << tmp[i][j] << ' ';
		}
		cout << endl;
	}

	return (0);
}
