#include <iostream>
using namespace std;

int X;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> X;
	int i = 0;
	int temp = 0;
	while (temp < X)
	{
		i++;
		temp += i;
	}
	temp -= X;
	if (i % 2 == 0)
		cout << i - temp << "/" << 1 + temp << "\n";
	else
		cout << 1 + temp << "/" << i - temp << "\n";
	return (0);
}
