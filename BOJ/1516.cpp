#include <iostream>
using namespace std;

int arr[501][501];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int temp1;
		cin >> temp1;
		arr[i + 1][1] = temp1;
		int j = 2;
		while (1)
		{
			int temp2;
			cin >> temp2;
			if (temp2 != -1)
				arr[i + 1][j++] = temp2;
			else
				break;
		}
		if (j == 2)
			arr[i + 1][0] = arr[i + 1][1];
	}
	for (int i = 1; i < N + 1; i++)
	{
		if (arr[i][0] != 0)
		{
			
		}
	}

	for (int i = 0; i < N + 1; i++)
	{
		for (int j = 0; j < N; j++)
			cout << arr[i][j] << " ";
		cout << "\n";
	}
	return (0);
}
