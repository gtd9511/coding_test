#include <iostream>
using namespace std;

long long gcd(long long a, long long b)
{
	if (a % b == 0)
		return (b);
	else
		return (gcd(b, a % b));
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	long long A, B, ans;

	cin >> A >> B;
	ans = A * B / gcd(A, B);
	cout << ans << endl;

	return (0);
}
2
