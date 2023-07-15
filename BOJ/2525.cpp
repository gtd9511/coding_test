#include <iostream>
using namespace std;

int main()
{
	int N, M, T;

	cin >> N >> M >> T;

	N += T / 60;
	M += T % 60;

	if (M >= 60) {
		N += M / 60;
		M %= 60;
	}
	if (N >= 24)
		N %= 24;
	cout << N << " " << M << endl;

	return (0);
}
