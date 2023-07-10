#include <iostream>
#include <algorithm>
using namespace std;

int arr[1000];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, k;
	cin >> N >> k;
	for (int i = 0; i < N; i++)
		cin >> arr[i];
	// for (int i = 0; i < N; i++)
		// cout << arr[i] << ' ';

	// cout << endl;
	sort(arr, arr + N);
	// for (int i = 0; i < N; i++)
		// cout << arr[i] << ' ';
	// cout << endl;
	cout << arr[N - k] << endl;

	return (0);
}
