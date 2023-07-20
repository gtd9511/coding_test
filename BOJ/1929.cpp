#include <iostream>
using namespace std;

int N, M;

bool nPrime[1000001] = {0, };

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> M;
	for (int i = 2; i < M + 1; i++)
	{
		if (nPrime[i] == 1)
			continue;
		for (int j = 2 * i ; j < M + 1; j += i)
			nPrime[j] = 1;
	}
	nPrime[1] = 1;
	nPrime[2] = 0;
	for (int i = N; i < M + 1; i++)
	{
		if (nPrime[i] == 0)
			cout << i << "\n";
	}
	return (0);
}
