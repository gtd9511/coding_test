#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int N;
	vector<int> v;
	cin >> N;
	while(N--)
	{
		int temp;
		cin >> temp;
		v.push_back(temp);
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < v.size(); i++)
		cout << v[i] << "\n";
	return (0);
}
