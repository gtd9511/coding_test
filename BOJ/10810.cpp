#include <iostream>
using namespace std;

int N, M;
int arr[100];

int main()
{
	cin >> N >> M;
	for (int i = 0; i < M; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		for (int i = a - 1; i < b; i++)
			arr[i] = c;
	}

	for (int i = 0; i < N; i++)
		cout << arr[i] << ' ';
	return (0);
}
