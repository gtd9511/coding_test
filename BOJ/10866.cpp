#include <iostream>
#include <deque>

using namespace std;

int N;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	deque<int> dq;

	cin >> N;
	while(N--)
	{
		string str;
		cin >> str;

		if (str == "push_front")
		{
			int temp;
			cin >> temp;
			dq.push_front(temp);
		}
		if (str == "push_back")
		{
			int temp;
			cin >> temp;
			dq.push_back(temp);
		}
		if (str == "pop_front")
		{
			if (dq.empty())
				cout << -1 << "\n";
			else
			{
				cout << dq.front() << "\n";
				dq.pop_front();
			}
		}
		if (str == "pop_back")
		{
			if (dq.empty())
				cout << -1 << "\n";
			else
			{
				cout << dq.back() << "\n";
				dq.pop_back();
			}
		}
		if (str == "size")
			cout << dq.size() << "\n";
		if (str == "empty")
		{
			if (dq.empty())
				cout << 1 << "\n";
			else
				cout << 0 << "\n";
		}
		if (str == "front")
		{
			if (dq.empty())
				cout << -1 << "\n";
			else
				cout <<dq.front() << "\n";
		}
		if (str == "back")
		{
			if (dq.empty())
				cout << -1 << "\n";
			else
				cout <<dq.back() << "\n";
		}
	}
	return (0);
}
