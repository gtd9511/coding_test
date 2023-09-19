#include <iostream>
#include <map>
using namespace std;

long long n;
map<long long, int> fibo_map;

long long fibo(long long n)
{
	if (n == 0)
		return 0;
	else if (n == 1)
		return 1;
	else if (n == 2)
		return 1;
	else if (n % 2)
	{
		if (fibo_map.find((n + 1) / 2) == fibo_map.end())
			fibo_map.insert(std::pair<long long, int>((n + 1) / 2, (fibo((n + 1) / 2) % 1000000007)));
		if (fibo_map.find((n - 1) / 2) == fibo_map.end())
			fibo_map.insert(std::pair<long long, int>((n - 1) / 2, (fibo((n - 1) / 2) % 1000000007)));
		long long a = fibo_map[(n + 1) / 2];
		long long b = fibo_map[(n - 1) / 2];
		return ((a * a + b * b) % 1000000007);
	}
	else
	{
		if (fibo_map.find(n / 2) == fibo_map.end())
			fibo_map.insert(std::pair<long long, int> (n / 2, (fibo(n / 2) % 1000000007)));
		if (fibo_map.find((n / 2 - 1)) == fibo_map.end())
			fibo_map.insert(std::pair<long long, int> ((n / 2 - 1), (fibo((n / 2 - 1)) % 1000000007)));
		long long a = fibo_map[n / 2];
		long long b = fibo_map[n / 2 - 1];
		return ((a * (2 * b + a)) % 1000000007);
	}
}

int main()
{
	cin >> n;
	cout << fibo(n);
	return (0);
}

//F[2n] = F[n]x(2F[n-1] + F[n])
//F[2n+1] = F[n+1]^2 + F[n]^2
