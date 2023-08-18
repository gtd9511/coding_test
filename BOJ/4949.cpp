#include <iostream>
#include <stack>

using namespace std;

int main()
{
	while(1)
	{
		string str;
		cin >> str;
		stack<int> s1;
		stack<int> s2;
		int flag1 = 0;
		int flag2 = 0;
		if (str[0] == '.' && str.length() == 1)
			break;
		else
		{

			int i = 0;
			for (int i = 0; i < str.length(); i++)
			{
				if (str[i] == '(')
				{
					s1.push(1);
					flag1 = 1;
					if (flag2 == 1)
						flag2 = 2;
				}
				else if (str[i] == '[')
				{
					s2.push(1);
					flag2 = 1;
					if (flag1 == 1)
						flag1 = 2;
				}
				else if (str[i] == ')' && flag1 == 1)
				{
					s1.pop();
					flag1 = 0;
				}
				else if (str[i] == ']' && flag2 == 1)
				{
					s2.pop();
					flag2 = 0;
				}
				// cout << "s1 size : " << s1.size() << endl;
				// cout << "s2 size : " << s2.size() << endl;
				// cout << "flag 1 : " << flag1 << endl;
				// cout << "flag 2 : " << flag2 << endl;
			}
			// cout << "s1 size : " << s1.size() << endl;
			// cout << "s2 size : " << s2.size() << endl;
			// cout << "flag 1 : " << flag1 << endl;
			// cout << "flag 2 : " << flag2 << endl;
		}
		if (s1.size() || s2.size() || flag1 || flag2)
			cout << "no\n";
		else
		 	cout << "yes\n";
	}
	return (0);
}
