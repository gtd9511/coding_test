#include <iostream>
#include <algorithm>
using namespace std;

long long N, B, C;
long long arr[1000003];
long long ans = 0;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> B >> C;
	for(int i = 0; i < N; i++)
		cin >> arr[i + 1];

	if (B <= C)
	{
		for(int i = 1; i <= N; i++)
			ans += arr[i];
		cout << ans * B << endl;
		return (0);
	}
	for(int i = 1; i <= N; i++)
	{
		if(arr[i + 1] > arr[i + 2])
		{
			long long a = min(arr[i], arr[i + 1] - arr[i + 2]);
			ans += (B + C) * a;
			arr[i] -= a;
			arr[i + 1] -= a;

			long long b = min(arr[i], min(arr[i + 1], arr[i + 2]));
			ans += (B + 2 * C) * b;
			arr[i] -= b;
			arr[i + 1] -= b;
			arr[i + 2] -= b;
		}
		else
		{
			long long a = min(arr[i], min(arr[i + 1], arr[i + 2]));
			ans += (B + C + C) * a;
			arr[i] -= a;
			arr[i + 1] -= a;
			arr[i + 2] -= a;

			long long b = min(arr[i], arr[i + 1]);
			ans += (B + C) * b;
			arr[i] -= b;
			arr[i + 1] -= b;
		}
		ans += B * arr[i];
	}
	cout << ans << endl;
	return (0);
}
