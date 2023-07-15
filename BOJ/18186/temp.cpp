#include <iostream>
using namespace std;

int main()
{
	for (int i = 0; i < 100; i++)
		cout << "1000000" << endl;
	return (0);
}

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
long long B, C;
int n = 1000003;
vector<long long> arr(n);
// vector<int> arr;
long long ans = 0;
//	100 000 000 000 000
int main()
{
	cin >> N >> B >> C;

	// for (int i = 1; i <= N; i++)
	// 	cin >> arr[i];
	arr.push_back(0);
	for (int i = 1; i <= N; i++)
	{
		long long temp = 0;
		cin >> temp;
		arr[i] = temp;
	}

	if (B <= C)
	{
		// cout << "1 : " << arr[0] << " " << arr[1] << " " << arr[2] << endl;
		for (int i = 1; i <= N; i++)
			ans += arr[i] * B;
		cout << ans << endl;
		return (0);
	}
	else
	{
		for(int i = 1; i <= N; i++)
		{
			if(arr[i + 1] > arr[i + 2])
			{
				long long a = min(arr[i], arr[i + 1] - arr[i + 2]);
				ans += (B + C) * a;
				arr[i] -= a;
				arr[i + 1] -= a;

				long long b = min(arr[i], min(arr[i + 1], arr[i + 2]));
				ans += (B) + 2 * C)) * b);
				arr[i] -= b;
				arr[i + 1] -= b;
				arr[i + 2] -= b;
			}
			else
			{
				long long a = min(arr[i], min(arr[i + 1], arr[i + 2]));
				ans += (B) + 2 * C)) * a);
				arr[i] -= a;
				arr[i + 1] -= a;
				arr[i + 2] -= a;

				long long b = min(arr[i], arr[i + 1]);
				ans += (B) + C)) * b);
				arr[i] -= b;
				arr[i + 1] -= b;
			}
			ans += 3 * arr[i]);
		}
		cout << ans << endl;
	}
	return (0);
}
