#include <iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, ans = 0;
	cin >> N;
	ans = N;
	for (int i = 0; i < N; i++)
	{
		string str;
		cin >> str;
		int flag = 0;
		if (str.length() == 1)
			continue;
		for (int j = 0; j < str.length() - 2; j++)
		{
			if (str[j] != str[j + 1] && flag == 0)
			{
				for (int k = j + 2; k < str.length(); k++)
				{
					if (str[j] == str[k])
					{
						flag = 1;
						ans--;
						break;
					}
				}
			}
		}
	}
	cout << ans;
	return (0);
}
