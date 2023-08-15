#include <iostream>
#include <stack>

using namespace std;

int N;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	stack<int> s;
	cin.ignore();

	for (int i = 0; i < N; i++)
	{
		string str;
		getline(cin, str);
		if (str.find("push") != string::npos)
		{
			int temp = stoi(str.substr(5));
			s.push(temp);
		}
		if (str.find("pop") != string::npos)
		{
			if (s.empty())
				cout << -1 << "\n";
			else
			{
			 	cout << s.top() << "\n";
				s.pop();
			}
		}
		if (str.find("size") != string::npos)
			cout << s.size() << "\n";
		if (str.find("empty") != string::npos)
		{
			if (s.empty())
				cout << 1 << "\n";
			else
			 	cout << 0 << "\n";
		}
		if (str.find("top") != string::npos)
		{
			if (s.empty())
				cout << -1 << "\n";
			else
				cout << s.top() << "\n";
		}
	}
}
