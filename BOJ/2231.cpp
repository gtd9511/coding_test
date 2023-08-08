#include <iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int temp = i;
		int sum = i;
		while (temp > 0)
		{
			sum += temp % 10;
			temp /= 10;
		}
		if (sum == n)
		{
			cout << i << "\n";
			return (0);
		}
	}
	cout << 0 << "\n";
	return (0);
}


