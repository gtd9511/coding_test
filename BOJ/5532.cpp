#include <iostream>
using namespace std;

int main()
{
	int L, A, B, C, D;
	cin >> L >> A >> B >> C >> D;
	if (A / C > B / D)
	{
		if (A % C == 0)
			cout << L - (A / C) << endl;
		else
			cout << L - (A / C) - 1 << endl;
	}
	else
	{
		if (B % D == 0)
			cout << L - (B / D) << endl;
		else
			cout << L - (B / D) - 1 << endl;
	}
	return (0);
}
