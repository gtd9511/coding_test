#include <iostream>
using namespace std;
int N, M;
int ans = 0;
int mans = 0;
int main()
{
	cin >> N >> M;
	for (int i  = M; i >= N; i--)
	{
		if (i == 1)
			continue;
		if (i == 2)
		{
			ans += i;
			mans = i;
			continue;
		}
		for (int j = 2; j < i; j++)
		{
			if (i % j == 0)
				break;
			if (j == i - 1)
			{
				ans += i;
				mans = i;
			}
		}
	}
	if (mans == 0)
		cout << -1;
	else
	 	cout << ans << "\n" << mans;
	return (0);
}
