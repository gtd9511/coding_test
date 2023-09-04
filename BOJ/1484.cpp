#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int N;
	bool flag = 0;
	cin >> N;
	for (int i = sqrt(N); i > 0; i--)
	{
		if (N % i == 0)
		{
			// cout << i << " ";
			if (!((N % 2 == 1) && (i % 2 == 0)) && (((N / i) % 2 != 0 && i % 2 != 0) || ((N / i) % 2 == 0 && i % 2 == 0)) && ((N / i + i) / 2 != 0 && (N / i - i) / 2 != 0))
			{
				// cout << i << endl;
				cout << (N / i + i) / 2 << "\n";
				flag = 1;
				// cout << (N / i - i) / 2 << endl;
			}
		}
		// cout << endl;
	}
	if (!flag)
		cout << -1 << "\n";
	return (0);
}
// 8	2	4	3	1
// 8	1	8	4.5	3.5
// 4	2 2

// 2a 2b
// 2 1			a+b a-b N  3 1 4
//	5	3 2		5 1
// 8 	3 1		4 2 8
// (a + b) (a - b) <= 100000
// 50000 49999
//99999 1
// 2a 2b

// 27778222224
// 27777222225
// 250000000000
// 249999000001
