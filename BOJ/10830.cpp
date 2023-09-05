#include<iostream>
using namespace std;

int N;
long long B;
int arr[5][5];
int tmp[5][5];
int ans[5][5];

void multiMatirx(int X[5][5], int Y[5][5])
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			tmp[i][j] = 0;
			for (int k = 0; k < N; k++)
				tmp[i][j] += (X[i][k] * Y[k][j]);
			tmp[i][j] %= 1000;
		}
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
			X[i][j] = tmp[i][j];
	}
}

int main()
{
	cin >> N >> B;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
			cin >> arr[i][j];
		ans[i][i] = 1;
	}

	while (B > 0)
	{
		if (B % 2)
			multiMatirx(ans, arr);
		multiMatirx(arr, arr);
		B /= 2;
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
			cout << ans[i][j] << " ";
		cout << endl;
	}
	return (0);
}

