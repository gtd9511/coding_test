#include <iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	int ans = 0;
	cin >> N;
	char str[100];
	for (int i = 0; i < 100; i++)
		str[i] = '0';
	cin.ignore();
	cin.getline(str, 100);
	for (int i = 0; i < 100; i++)
	{
		if ((str[i] - '0' >= 0) && (str[i] - '0') < 10)
		{
			int a = 0;
			// cout << "i : " << i << " ";
			// cout << str[i] << " ";
			a = str[i] - '0';
			// cout << " a : " << a << endl;
			ans += a;
		}
	}
	cout << ans << '\n';
	return (0);
}
