#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, ans = -1;
vector<pair<int, int> > v;

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int temp;
		cin >> temp;
		v.push_back(make_pair(temp, i));
	}

	sort(v.begin(), v.end());

	for (int i = 0; i < n; i++)
		ans = ans > (v[i].second - i) ? ans : (v[i].second - i);

	cout << ans + 1;
	return (0);
}
// 10 1 5 2 3
// 1 2 3 5 10
// 10 1 5 2 3
// 1 5 2 3 10
// 1 2 3 5 10
