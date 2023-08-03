#include <iostream>
using namespace std;

int main()
{
	while (1)
	{
		int N;
		int temp = 0;
		cin >> N;
		if (N == -1)
			break;
		for (int i = 1; i < N; i++)
		{
			if (N % i == 0)
				temp += i;
		}
		if (temp != N)
			cout << N << " is NOT perfect.\n";
		else
		{
			cout << N << " = ";
			for (int i = 1; i < N; i++)
			{
				if (i == 1)
					cout << 1;
				else if (N % i == 0)
					cout << " + " << i;
			}
			cout << "\n";
		}

	}
	return (0);
}
