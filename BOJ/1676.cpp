#include <iostream>
using namespace std;

int main()
{
	size_t N, cnt = 0;
	cin >> N;
	while (N > 0)
	{
		while (N % 5 == 0)
		{
			cnt += N / 5;
			N /= 5;
		}
		N--;
	}
	cout << cnt;
	return (0);
}
