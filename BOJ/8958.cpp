#include <iostream>
using namespace std;

int N;
string str;

int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> str;
		int score = 0;
		int ans = 0;
		bool flag = false;

		for (int i = 0; i < str.size(); i++)
		{
			if (str[i] == 'O' && flag == true)
				score++;
			if (str[i] == 'O' && flag == false)
			{
				score = 1;
				flag = true;
			}
			if (str[i] == 'X')
			{
				score = 0;
				flag = false;
			}
			ans += score;
		}
		cout << ans << endl;
	}
	return (0);
}
