#include <iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	int arr[201] = {0, };

	for (int i = 0; i < N; i++)
	{
		int a;
		cin >> a;
		arr[a + 100]++;
	}
	int v;
	cin >> v;
	cout << arr[v + 100];
	return (0);
}
