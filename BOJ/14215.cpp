#include <iostream>
using namespace std;

int main()
{
	int a, b, c;
	cin >> a >> b >> c;
	int temp1 = max (a, b);
	int maxV = max (temp1, c);
	if (maxV >= a + b + c - maxV)
		cout << 2 * (a + b + c - maxV) - 1;
	else
		cout << a + b + c;
	return (0);
}
