#include <iostream>
#include <vector>
using namespace std;

int N, M;
int arr[100001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;

	for (int i = 1; i < N + 1; i++)
	{
		cin >> arr[i];
		arr[i] += arr[i - 1];
	}

	for (int i = 0; i < M; i++)
	{
		int start, end;
		cin >> start >> end;
		cout << arr[end] - arr[start - 1] << "\n";
	}
	return (0);
}
