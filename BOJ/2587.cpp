#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int ans1 = 5;
	int ans2;
	vector<int> v;

	while (ans1--)
	{
		cin >> ans2;
		v.push_back(ans2);
	}
	sort(v.begin(), v.end());
	cout << (v[0] + v[1] + v[2] + v[3] + v[4]) / 5 << "\n" << v[2];
	return(0);
}
