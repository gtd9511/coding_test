#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int N;
vector <string> v;

bool comp_length(string a, string b)
{
	if (a.length() == b.length())
		return (a < b);
	return (a.length() < b.length());
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;

	while (N--)
	{
		string s;
		cin >> s;
		v.push_back(s);
	}

	sort(v.begin(), v.end(), comp_length);
	v.erase(unique(v.begin(), v.end()), v.end());
	for (int i = 0; i < v.size(); i++)
		cout << v[i] << "\n";
	return (0);
}
