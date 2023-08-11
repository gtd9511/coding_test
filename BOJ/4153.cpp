#include <iostream>
using namespace std;

int main()
{
	while(1)
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);
		int a, b, c, maxNum;
		cin >> a;
		maxNum = a;
		cin >> b;
		if (a < b)
			maxNum = b;
		cin >> c;
		if (maxNum < c)
			maxNum = c;
		if (a == 0 && b == 0 && c== 0)
			break;
		if (2 * maxNum * maxNum == a * a + b * b + c * c)
			cout << "right\n";
		else
		 	cout << "wrong\n";
	}
	return (0);
}
