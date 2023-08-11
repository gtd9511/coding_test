#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

size_t K, N ,ans;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> K >> N;
	vector<size_t> v(K);
	for (int i = 0; i < K; i++)
		cin >> v[i];

	size_t low = 1, high = *max_element(v.begin(), v.end());
	int cnt = 0;
	while (low <= high)
	{
		size_t mid = (low + high) / 2;
		cnt = 0;
		for (int i = 0; i < K; i++)
			cnt += v[i] / mid;
		if (cnt >= N)
		{
			ans = mid;
			low = mid + 1;
		}
		else
			high = mid - 1;
	}
	cout << ans;
	return (0);
}
