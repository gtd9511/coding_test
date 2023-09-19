#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	long long n, ans = 0;
	cin >> n;
	long long prev = n;
	for (long long i = 1; i <= static_cast<long long>(sqrt(n)); i++)
	{
		long long temp = 0;
		temp = n / i;
		if (n % i != 0)
			temp++;
		ans += temp;
		if (i != 1)
		{
			ans += (prev - temp) * i;
			prev = temp;
		}
		else if (i == 1)
			ans++;
		if (i == static_cast<long long>(sqrt(n)) && temp - i > 1)
			ans += (temp - i - 1) * (temp - 1);
		else if (i == static_cast<long long>(sqrt(n)) && temp == i)
			ans -= temp;

	}
	cout << ans;
	return (0);
}

// 3	6
// 4	9
// 5	13
// 6	16
// 7	21
// 12	41
