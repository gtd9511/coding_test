#include <iostream>
using namespace std;

string N;
int B, ans;

int main()
{
	cin >> N >> B;
	for (int i = 0; i < N.length(); i++)
	{
		int temp = 1;
		int A = 0;
		for (int j = N.length() - 2 - i; j >= 0; j--)
			temp *= B;
		if (N[i] >= 48 && N[i] <= 57)
			A = N[i] - '0';
		else if (N[i] >= 65 && N[i] <= 90)
			A = N[i] - 55;
		ans += temp * A;
	}
	cout << ans;
	return (0);
}
