#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int n, ans = 0;
	cin >> n;
	int prev = n;
	for (int i = 1; i <= static_cast<int>(sqrt(n)); i++)
	{
		int temp = 0;
		temp = n / i;
		if (n % i != 0)
			temp++;
		ans += temp;

		if (i != 1)
		{
			ans += (prev - temp) * i;
			prev = temp;
		}
		else
			ans++;

		// cout << "i : " << i << " temp : " << temp << " prev : " << aaa << " plus : " << (aaa - temp) * i << endl;

	}
	cout << ans;
	return (0);
}

//3

//1 3

//2 2
//3 1

//4
// 1	4	1 * 1
// 2	2	2 * 1

// 4 + 2 + 2 + 1

//3 2
//4 1


// 5
// 1	5	1 * 1
// 2	3	2 * 2

// 5 + 3 + 4 + 1

// 3 2
// 4 2
// 5 1

// 12
// 1	12	1 * 1
// 2	6	6 * 2
// 3	4	2 * 3

// 12 + 6 + 4 + 6 + 12 + 1

// 4	3
// 5	3
// 6	2
// 7	2
// 8	2
// 9	2
// 10	2
// 11	2
// 12	1
