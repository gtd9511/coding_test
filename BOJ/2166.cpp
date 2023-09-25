#include <iostream>
#include <iomanip>
using namespace std;

int N;
long long x[10000] = {0, }, y[10000] = {0, }, temp1 = 0, temp2 = 0;
int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> x[i] >> y[i];
	for (int i = 0; i < N; i++)
	{
		if (i != N - 1)
		{
			temp1 += x[i] * y[i + 1];
			temp2 += y[i] * x[i + 1];
		}
		else
		{
			temp1 += x[i] * y[0];
			temp2 += y[i] * x[0];
		}
	}
	if (temp1 > temp2)
	{
		cout << fixed << setprecision(1) << (temp1 - temp2) / 2;
		if ((temp1 - temp2) % 2)
			cout << ".5";
		else
		 	cout << ".0";
	}
	else
	{
		cout << fixed << setprecision(1) << (temp2 - temp1) / 2;
		if ((temp1 - temp2) % 2)
			cout << ".5";
		else
		 	cout << ".0";
	}
	return (0);
}
