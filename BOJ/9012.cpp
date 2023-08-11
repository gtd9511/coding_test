#include <iostream>
#include <string>
#include <stack>

using namespace std;

int N;

int main()
{
	cin >> N;
	while (N--)
	{
		stack<int> s;
		string str;
		bool flag = false;
		cin >> str;
		for (int i = 0; i < str.length(); i++)
		{
			if (str[i] == '(')
				s.push(1);
			else if (str[i] == ')')
			{
				if (s.size() == 0)
				{
					flag = true;
					break;
				}
				s.pop();
			}
		}

		if (s.size() == 0 && flag == false)
			cout << "YES\n";
		else
			cout << "NO\n";
	}
	return (0);
}

