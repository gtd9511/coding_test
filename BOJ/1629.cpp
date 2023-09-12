#include <iostream>
#include <vector>
using namespace std;

long long A, B, C, ans = 1;
vector<bool> vec;

int main()
{
	cin >> A >> B >> C;
	while (B > 0)
	{
		if (B % 2)
		{
			B--;
			vec.push_back(0);
		}
		else
		{
			B /= 2;
			vec.push_back(1);
		}
	}
	for (int i = vec.size() - 1; i >= 0; i--)
	{
		if (vec[i] == 1)
		{
			ans *= (ans % C);
			if (ans >= C)
				ans %= C;
		}
		else
		{
			ans *= (A % C);
			if (ans >= C)
				ans %= C;
		}
	}
	cout << ans << "\n";
	return (0);
}
