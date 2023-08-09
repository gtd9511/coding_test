#include <iostream>
using namespace std;

int main()
{
	int N;
	cin >> N;

	int ans = 0;

	while (N != 0)
	{
		if (N % 5 == 0)
		{
			ans += N / 5;
			N = 0;
		}
		else
		{
			N -= 3;
			ans++;
		}
		if (N < 0)
		{
			ans = -1;
			break;
		}
	}
	cout << ans;
	return (0);
}
