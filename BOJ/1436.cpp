#include <iostream>
using namespace std;

int main()
{
	int N;
	cin >> N;

	int cnt = 0;
	int num = 666;
	while (cnt < N)
	{
		int tmp = num;
		while (tmp)
		{
			if (tmp % 1000 == 666)
			{
				cnt++;
				break;
			}
			tmp /= 10;
		}
		num++;
	}
	cout << num - 1 << "\n";
	return (0);
}
