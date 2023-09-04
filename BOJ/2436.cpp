#include <iostream>
#include <cmath>
using namespace std;

long long gcd(long long a, long long b)
{
	if (a % b == 0)
		return b;
	else
		return gcd(b, a % b);
}

int main()
{
	long long num1, num2;
	long long ans1 = 0, ans2 = 0;
	cin >> num1 >> num2;
	for (long long i = sqrt(num1 * num2); i > 0; i--)
	{
		if (((num1 * num2) % i == 0))
		{
			if (gcd((num1 * num2) / i, i) == num1)
			{
				ans1 = i;
				break;
			}
		}
	}
	ans2 = num1 * num2 / ans1;
	cout << ans1 << " " << ans2 << endl;

	return (0);
}

// 43243200
// 6 180
// 6 30
// 6 6 6 5
// 2 3 3 3 5
// 2 2 43243200

// 1080
// a1 n  a2 n
// n    n a1 a2

