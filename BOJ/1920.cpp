#include <iostream>
#include <algorithm>
using namespace std;

#define ll long long

ll N, M, arr[100000] = { 0, };

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for (ll i = 0; i < N; ++i)
		cin >> arr[i];
	sort(arr, arr + N);
	cin >> M;
	for (ll i = 0; i < M; i++)
	{
		ll temp, low = 0, high = N - 1;
		bool flag = false;

		cin >> temp;
		while (low <= high)
		{
			ll mid = (low + high) / 2;
			// cout << "Debug : " << low << " " << mid << " " << high << '\n';
			if (arr[mid] == temp)
			{
				flag = true;
				break;
			}
			else if (arr[mid] < temp)
				low = mid + 1;
			else
				high = mid - 1;
		}
		cout << flag << '\n';
	}
	return (0);
}

