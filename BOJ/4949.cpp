#include <iostream>
#include <stack>

using namespace std;

int main()
{
	while(1)
	{
		string str;
		getline(cin, str, '.');
		stack<int> s;
		bool flag = false;

		if (str.length() == 0)
			break;
		else
		{
			int i = 0;
			for (int i = 0; i < str.length(); i++)
			{
				if (str[i] == '(')
					s.push(1);
				else if (str[i] == '[')
					s.push(2);
				else if (str[i] == ')')
				{
					if (s.empty())
						flag = true;
					else if (s.top() == 1)
						s.pop();
					else
						flag = true;
				}
				else if (str[i] == ']')
				{
					if (s.empty())
						flag = true;
					else if (s.top() == 2)
						s.pop();
					else
						flag = true;
				}
				// cout << "str[i] : " << str[i] << " statck size : " << s.size() << endl;
			}
			cin.ignore();
		}
		if (s.size() != 0 || flag)
			cout << "no\n";
		else
		 	cout << "yes\n";
		while (!s.empty())
			s.pop();
	}
	return (0);
}
