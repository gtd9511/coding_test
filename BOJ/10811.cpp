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
		int A, B;
		cin >> A >> B;
		for (int j = A - 1; j < B; j++)
		{
			if (j >= A + B - j - 2)
				break ;
			int temp = arr[j];
			arr[j] = arr[A + B - j - 2];
			arr[A + B - j - 2] = temp;
		}
	}
	for (int i = 0; i < N; i++)
		cout << arr[i] << ' ';
	return (0);
}
