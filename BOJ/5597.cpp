#include <iostream>
using namespace std;

bool submit[30];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	for (int i = 0; i < 28; i++)
	{
		int temp;
		cin >> temp;
		submit[temp - 1] = true;
	}
	for (int i = 0; i < 30; i++)
		if (!submit[i])
			cout << i + 1 << '\n';

	return (0);
}
