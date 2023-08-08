#include <iostream>
using namespace std;

int main()
{
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	for (int i = d; i <= 100; i++)
	{
		if ((c * i) < (a * i + b))
		{
			cout << 0;
			return (0);
		}
	}
	cout << 1;
	return (0);
}
