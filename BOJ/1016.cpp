#include <iostream>
using namespace std;
bool check[1000001] = {0, };
int main()
{
	long long min, max, cnt = 0;
	cin >> min >> max;
	for (long long i = 2; i * i <= max; i++)
	{
		long long n = min / (i * i);

		if (min % (i * i))
			n++;

		while (n * i * i <= max)
		{
			check[n * i * i - min] = 1;
			n++;
		}
	}

	for (int i = 0; i < max - min + 1; i++)
	{
		if (check[i] == 1)
			cnt++;
	}
	cout << max - min + 1 - cnt;
	return (0);
}
