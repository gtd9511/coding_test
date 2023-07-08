#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int K;
	int res[30] = {0, };
	cin >> K;

	int temp = K + 1;
	int idx = 0;
	while (temp > 1)
	{
		temp /= 2;
		idx++;
	}
	temp = K - pow(2, idx) + 1;

	for (int j = 0; j < 30; j++)
	{
		if (j > 29 - idx)
			res[j] = 4;
	}
	idx = 29;
	while (temp > 0)
	{
		if (temp % 2 == 1)
			res[idx] = 7;
		idx--;
		temp /= 2;
	}
	for (int j = 0; j < 30; j++)
	{
		if (res[j] != 0)
		cout << res[j];
	}
	return (0);
}
