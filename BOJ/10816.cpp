#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;

int main()
{
	vector<int> v;

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int temp;
		cin >> temp;
		v.push_back(temp);
	}
	sort(v.begin(), v.end());
	cin >> M;
	for (int i = 0; i < M; i++)
	{
		int temp;
		cin >> temp;
		cout << upper_bound(v.begin(), v.end(), temp) - lower_bound(v.begin(), v.end(), temp) << " ";
	}
	return (0);
}
