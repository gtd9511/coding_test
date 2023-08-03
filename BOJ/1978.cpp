#include <iostream>
using namespace std;

int N;
int arr[100] = {0, };

int main()
{
	int ans = 0;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
		if (arr[i] == 1)
			continue;
		if (arr[i] == 2)
		{
			ans++;
			continue;
		}
		for (int j = 2; j < arr[i]; j++)
		{
			if (arr[i] % j == 0)
				break;
			if (j == arr[i] - 1)
				ans++;
		}
	}
	cout << ans;
	return (0);
}
