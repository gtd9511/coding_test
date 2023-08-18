#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int arr[300001] = {0, };

int main()
{
	int n;
	cin >> n;
	if (n == 0)
	{
		cout << 0;
		return (0);
	}
	int idx = round(static_cast<double>(n) * 15 / 100);
	// cout << idx;
	for (int i = 1; i <= n; i++)
	{
		int temp;
		cin >> temp;
		arr[i] = temp;
	}
	sort(arr, arr + n + 1);
	// for (int i = 0; i <= n; i++)
		// cout << arr[i] << " ";
	int ans = 0;
	for (int i = idx + 1; i <= n - idx; i++)
		ans += arr[i];

	// cout << "idx : " << idx << endl;
	// cout << "total : " << ans << endl;
	// cout << "po : " << n - 2 * idx << endl;
	cout << round(static_cast<double>(ans) / (n - 2 * idx));
	return (0);
}
