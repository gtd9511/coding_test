#include <iostream>
using namespace std;

int N, M;
int arr[100];

int main()
{
	cin >> N >> M;
	for (int i = 0; i < N; i++)
		arr[i] = i + 1;
	for (int i = 0; i < M; i++)
	{
		int a, b, temp;
		cin >> a >> b;
		temp = arr[a - 1];
		arr[a - 1] = arr[b - 1];
		arr[b - 1] = temp;
	}
	for (int i = 0; i < N; i++)
		cout << arr[i] << ' ';
	return (0);
}
