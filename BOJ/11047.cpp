#include <iostream>
using namespace std;

int N, K;
int arr[10];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int ans = 0;
	cin >> N >> K;
	for (int i = 0; i < N; i++)
		cin >> arr[i];

	int temp = 9;
	while (K)
	{
		if (arr[temp] != 0)
		{
			ans += K / arr[temp];
			K %= arr[temp];
			// cout << "ans : " << ans << endl;
			// cout << "남은값 : " << K << endl;
		}
		temp--;
	}
	cout << ans;
	return (0);
}
