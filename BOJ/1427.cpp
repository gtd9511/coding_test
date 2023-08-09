#include <iostream>
using namespace std;

int N;
int arr[10];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	while (N)
	{
		N % 10 ? arr[N % 10]++ : arr[0]++;
		N /= 10;
	}
	for (int i = 9; i >= 0; i--)
		for (int j = 0; j < arr[i]; j++)
			cout << i;
	return (0);
}
