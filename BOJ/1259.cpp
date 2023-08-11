#include <iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	while(1)
	{
		string s;
		cin >> s;
		if (s == "0")
			break;
		int len = s.length();
		bool flag = true;
		for (int i = 0; i < len / 2; i++)
		{
			if (s[i] != s[len - i - 1])
			{
				flag = false;
				break;
			}
		}
		if (flag)
			cout << "yes\n";
		else
			cout << "no\n";
	}
	return (0);
}
