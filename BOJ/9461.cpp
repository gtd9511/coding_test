#include <iostream>
using namespace std;

long long arr[101];

void solve()
{
	arr[1] = 1;
	arr[2] = 1;
	arr[3] = 1;
	arr[4] = 2;
	arr[5] = 2;
	for (int i = 6; i < 101; i++)
		arr[i] = arr[i - 1] + arr[i - 5];
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	solve();

	int T;
	cin >> T;
	while(T--)
	{
		int temp;
		cin >> temp;
		cout << arr[temp] << "\n";
	}
	return (0);
}
