#include <iostream>
using namespace std;

int N, S;
int arr[100001] = {0, };

int main()
{
	ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	cin >> N >> S;
	for (int i = 1; i <= N; i++)
	{
		cin >> arr[i];
		if (i)
			arr[i] += arr[i - 1];
	}

	int ans = 100002, s = 1, e = 1;
	while (s <= N)
	{
		if (e == s && arr[e] - arr[e - 1] >= S)
		{
			cout << 1;
			return (0);
		}
		else if (arr[e] - arr[s - 1] >= S)
		{
			if (e - s + 1 < ans)
				ans = e - s + 1;
			s++;
		}
		else if (arr[e] - arr[s - 1] < S && e < N)
			e++;
		else if (e == N)
			s++;
	}
	if (ans != 100002)
		cout << ans;
	else
	 	cout << 0;

	return (0);
}
