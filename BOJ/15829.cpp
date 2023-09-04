#include <iostream>

using namespace std;

int main()
{
	unsigned long long L;
	unsigned long long res = 0;
	cin >> L;
	string str;
	cin >> str;
	for (int i = 0; i < str.length(); i++)
	{
		int temp = i;
		unsigned long long temp_v = str[i] - 'a' + 1;
		while(temp--)
		{
			temp_v *= 31;
			temp_v %= 1234567891;
		}
		res += temp_v % 1234567891;
	}
	cout << res % 1234567891;
	return (0);
}
