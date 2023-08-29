#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector <int> vec;

int main()
{
	int min = 1;
	int max = 0;
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		int temp;
		cin >> temp;
		vec.push_back(temp);
		if (max < temp)
			max = temp;
	}

	long long total = 0;
	int ans = 0;

	while (min <= max)
	{
		int mid = (min + max) / 2;
		long long temp_total = 0;
		for (int i = 0; i < N; i++)
			if (vec[i] > mid)
				temp_total += (vec[i] - mid);
		if (total == 0)
			total = temp_total;
		// cout << "min : " << min << endl;
		// cout << "mid : " << mid << endl;
		// cout << "max : " << max << endl;
		// cout << "ans : " << ans << endl;
		// cout << "total : " << temp_total << endl;
		// cout << "temp_total : " << temp_total << endl;
		if (temp_total == M)
		{
			ans = mid;
			break;
		}
		if (temp_total > M)
		{
			if (total > temp_total)
				total = temp_total;
			ans = mid;
			min = mid + 1;
		}
		if (temp_total < M)
			max = mid - 1;
	}
	cout << ans;

	return (0);
}

//6 4 10
