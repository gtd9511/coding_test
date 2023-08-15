#include <iostream>
#include <queue>

using namespace std;

int N;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	queue<int> q;

	cin >> N;
	while (N--)
	{
		string str;
		cin >> str;
		if (str == "push")
		{
			int temp;
			cin >> temp;
			q.push(temp);
		}
		if (str == "pop")
		{
			if (q.empty())
				cout << -1 << "\n";
			else
			{
				cout << q.front() << "\n";
				q.pop();
			}
		}
		if (str == "front")
		{
			if (q.empty())
				cout << -1 << "\n";
			else
				cout << q.front() << "\n";
		}
		if (str == "back")
		{
			if (q.empty())
				cout << -1 << "\n";
			else
				cout << q.back() << "\n";
		}
		if (str == "size")
			cout << q.size() << "\n";
		if (str == "empty")
		{
			if (q.empty())
				cout << 1 << "\n";
			else
				cout << 0 << "\n";
		}
	}
	return (0);
}
