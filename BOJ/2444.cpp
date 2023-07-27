#include <iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;

	cin >> N;

	for (int i = 0; i < 2 * N - 1; i++)
	{
		if (i < N)
		{
			for (int j = 0; j < N - i - 1; j++)
				cout << ' ';
			for (int j = 0; j < 2 * i + 1; j++)
				cout << '*';
		}
		else
		{
			for (int j = 0; j < i - N + 1; j++)
				cout << ' ';
			for (int j = 0; j < 4 * N - 2 * i - 3; j++)
				cout << '*';
		}
		cout << '\n';
	}
	return (0);
}
