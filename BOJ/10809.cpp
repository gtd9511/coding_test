#include <iostream>
using namespace std;

string str;

int main()
{
	cin >> str;
	for (int i = 0; i < 26; i++)
	{
		int j = 0;
		for (; j < str.length(); j++)
		{
			if (str[j] == 'a' + i)
			{
				cout << j << " ";
				break;
			}
		}
		if (j == str.length())
			cout << -1 << " ";
	}
	return (0);
}
