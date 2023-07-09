#include <iostream>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string str;
	cin >> str;

	int len = str.length();
	int cnt = 0;
	for (int i = 0; i < len; i++)
	{
		bool flag = true;
		for (int j = 0; j < len - i; j++)
		{
			if (str[i + j] != str[len - j - 1])
			{
				flag = false;
				break;
			}
		}
		if (flag)
		{
			cnt = len + i;
			break;
		}
	}
	cout << cnt << endl;
}
