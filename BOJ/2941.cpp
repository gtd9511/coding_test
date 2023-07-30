#include <iostream>
using namespace std;

string str;

int main()
{
	cin >> str;
	int i = 0;
	int cnt = 0;
	while(i < str.length())
	{
		if (str[i] == 'c' && str[i + 1] == '=')
			i += 2;
		else if (str[i] == 'c' && str[i + 1] == '-')
			i += 2;
		else if (str[i] == 'd' && str[i + 1] == 'z' && str[i + 2] == '=')
			i += 3;
		else if (str[i] == 'd' && str[i + 1] == '-')
			i += 2;
		else if (str[i] == 'l' && str[i + 1] == 'j')
			i += 2;
		else if (str[i] == 'n' && str[i + 1] == 'j')
			i += 2;
		else if (str[i] == 's' && str[i + 1] == '=')
			i += 2;
		else if (str[i] == 'z' && str[i + 1] == '=')
			i += 2;
		else
			i++;
		cnt++;
	}
	cout << cnt;
	return (0);
}
