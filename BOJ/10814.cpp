#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector <pair<int, string> > v;

bool compare_age(pair<int, string> a, pair<int, string> b)
{
	return (a.first < b.first);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	cin.ignore();
	while (N--)
	{
		int age;
		string name;
		cin >> age >> name;
		v.push_back(make_pair(age, name));
	}
	stable_sort(v.begin(), v.end(), compare_age);
	for (int i = 0; i < v.size(); i++)
		cout << v[i].first << " " << v[i].second << "\n";
	return (0);
}
