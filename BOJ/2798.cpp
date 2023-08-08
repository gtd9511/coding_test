#include <iostream>
using namespace std;

int N, M, ans;
int arr[100];

int main()
{
	cin >> N >> M;
	for (int i = 0; i < N; i++)
		cin >> arr[i];
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			for (int k = 0; k < N; k++)
			{
				int sum = arr[i] + arr[j] + arr[k];
				if (i == j || j == k || k == i)
					continue;
				if (sum <= M && ans < sum)
					ans = sum;
			}
		}
	}
	cout << ans;
	return (0);
}
