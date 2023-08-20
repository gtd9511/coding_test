#include <bits/stdc++.h>
using namespace std;

int N, K;

int combination(int n, int k)
{
	if (n == k || k == 0)
		return (1);
	return (combination(n - 1, k - 1) + combination(n - 1, k));
}

int main()
{
	cin >> N >> K;
	cout << combination(N, K);
	return (0);
}

