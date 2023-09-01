#include <iostream>
using namespace std;

int N, r, c;

int main()
{
	cin >> N >> r >> c;
	// N = 2 << N;
	int ans = 0;
	while (N > 0)
	{
		// std::cout << "case\n";
		// std::cout << "N : " << N << " r : " << r << " c : " << c << endl;
		// std::cout << "plus : " << ((1 << N) * (1 << N) / 4) << endl;
		if (r >= (1 << (N - 1)) && c >= (1 << (N - 1)))
		{
			ans += 3 *  ((1 << N) * (1 << N) / 4);
			r -= (1 << (N - 1));
			c -= (1 << (N - 1));
		}
		else if (r >= (1 << (N - 1)))
		{
			ans += 2 * ((1 << N) * (1 << N) / 4);
			r -= (1 << (N - 1));
		}
		else if (c >= (1 << (N - 1)))
		{
			ans += (((1 << N) * (1 << N) /4));
			c -= (1 << (N - 1));
		}
		// std::cout << "ans  : " << ans << endl << endl;
		N--;
	}
	std::cout << ans;
	return (0);
}


// 3 1

// 00 01 02 03
// 10 11 12 13
// 20 21 22 23
// 30 31 32 33

//2 ^ r + 2 ^ (r - 2) +
// 8 + 2 +


// 3 1
// 11		2 ^ r
// 5 0
// 34		2 ^ r
