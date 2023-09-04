#include <iostream>
using namespace std;

int arr[5][5] = {0, };
int temp[5][5] = {0, };
int prevarr[5][5] = {0, };
int N;
long long B;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> B;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> arr[i][j];
			temp[i][j] = arr[i][j];
		}
	}
	while (B--)
	{
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				prevarr[i][j] = arr[i][j];
				arr[i][j] = 0;
			}
		}

		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				arr[i][j] += (prevarr[i][j] * temp[j][i]) % 1000;
				cout << i << " " << j << ", " << j << " " << i << ", " << prevarr[i][j] << " " << temp[j][i] <<endl;
				cout << i << " " << j << " " << arr[i][j] << endl;
			}
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
			cout << (arr[i][j] % 1000) << " ";
		cout << "\n";
	}

	return (0);
}

// 1 2		1 2
// 3 4		3 4

// 7 10	1 2
// 15 22	3 4

// 37 54	1 2
// 81 118	3 4


