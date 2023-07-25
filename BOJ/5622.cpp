#include <iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string str;
	int ans = 0;

	cin >> str;

	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] == 'A' || str[i] == 'B' || str[i] == 'C')
			ans += 2;
		else if (str[i] == 'D' || str[i] == 'E' || str[i] == 'F')
			ans += 3;
		else if (str[i] == 'G' || str[i] == 'H' || str[i] == 'I')
			ans += 4;
		else if (str[i] == 'J' || str[i] == 'K' || str[i] == 'L')
			ans += 5;
		else if (str[i] == 'M' || str[i] == 'N' || str[i] == 'O')
			ans += 6;
		else if (str[i] == 'P' || str[i] == 'Q' || str[i] == 'R' || str[i] == 'S')
			ans += 7;
		else if (str[i] == 'T' || str[i] == 'U' || str[i] == 'V')
			ans += 8;
		else if (str[i] == 'W' || str[i] == 'X' || str[i] == 'Y' || str[i] == 'Z')
			ans += 9;
		else
			ans = 0;
	}
	ans += str.length();
	cout << ans << '\n';
	return (0);
}
