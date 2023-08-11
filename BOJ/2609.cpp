#include <iostream>
using namespace std;

int N, M, GCD;
int main()
{
	cin >> N >> M;
	int min;
	N > M ? min = M : min = N;
	for (int i = 1; i <= min; i++)
	{
		if (N % i == 0 && M % i == 0)
			GCD = i;
	}
	cout << GCD << "\n" << N * M / GCD;
	return (0);
}
