#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, ans = 0;
vector<int> P;

int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int temp;
		cin >> temp;
		P.push_back(temp);
	}

	sort(P.begin(), P.end());
	for (int i = 0; i < N; i++)
		ans += (N - i) * P[i];
	cout << ans;
	return (0);
}
