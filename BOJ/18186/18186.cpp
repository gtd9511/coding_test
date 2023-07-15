#include <iostream>
#include <algorithm>
using namespace std;

long long N, B, C;
long long arr[1000003];
long long ans=0;

int main()
{
	cin >> N >> B >> C;

	for(long i = 1; i <= N; i++)
		cin >> arr[i];

	if (B <= C)
	{
		for(long i = 1; i <= N; i++)
			ans += arr[i] * B;
		cout << ans << endl;
		return (0);
	}
	else
	{
		for(long i = 1; i <= N; i++)
		{
			if (arr[i] > 0 && arr[i + 1] > 0 && arr[i + 2] > 0)
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
					ans += (B + 2 * C) * a;
					arr[i] -= a;
					arr[i + 1] -= a;
					arr[i + 2] -= a;

					long long b = min(arr[i], arr[i + 1]);
					ans += (B + C) * b;
					arr[i] -= b;
					arr[i + 1] -= b;
				}
				ans += 3 * arr[i];
			}
		}
		cout << ans << endl;
	}
	return (0);
}
