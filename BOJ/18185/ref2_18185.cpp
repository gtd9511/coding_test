#include <iostream>
#include <algorithm>
using namespace std;

int N;
int arr[100001];
int ans=0;

int main()
{
	cin >> N;
	for(int i = 0; i < N; i++)
		cin >> arr[i + 1];
	for(int i = 1; i <= N; i++)
	{
		if(arr[i + 1] > arr[i + 2])
		{
			int a = min(arr[i], arr[i + 1] - arr[i + 2]);
			ans += 5 * a;
			arr[i] -= a;
			arr[i + 1] -= a;

			int b = min(arr[i], min(arr[i + 1], arr[i + 2]));
			ans += 7 * b;
			arr[i] -= b;
			arr[i + 1] -= b;
			arr[i + 2] -= b;
		}
		else
		{
			int a = min(arr[i], min(arr[i + 1], arr[i + 2]));
			ans += 7 * a;
			arr[i] -= a;
			arr[i + 1] -= a;
			arr[i + 2] -= a;

			int b = min(arr[i], arr[i + 1]);
			ans += 5 * b;
			arr[i] -= b;
			arr[i + 1] -= b;
		}
		ans += 3 * arr[i];
	}
	cout << ans << endl;
	return (0);
}
