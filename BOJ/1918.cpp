#include <iostream>
#include <stack>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	stack<char> op;

	string str;
	cin >> str;

	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			cout << str[i];
		if (str[i] == '(')
			op.push(str[i]);
		if (str[i] == '*' || str[i] == '/')
		{
			while (!op.empty() && (op.top() == '*' || op.top() == '/'))
			{
				cout << op.top();
				op.pop();
			}
			op.push(str[i]);
		}
		if (str[i] == '+' || str[i] == '-')
		{
			while (!op.empty() && op.top() != '(')
			{
				cout << op.top();
				op.pop();
			}
			op.push(str[i]);
		}
		if (str[i] == ')')
		{
			while (!op.empty() && op.top() != '(')
			{
				cout << op.top();
				op.pop();
			}
			op.pop();
		}
	}
	while (!op.empty())
	{
		cout << op.top();
		op.pop();
	}
	return (0);
}

// + -
// * /
// ()

//	A + B * C + D	ABC*+D+
//	A * B + C * D	AB*CD*+
//
//
//

