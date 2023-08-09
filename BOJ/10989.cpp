#include <iostream>
#include <locale>
using namespace std;

int N;
int arr[10001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	while (N--)
	{
		int temp;
		cin >> temp;
		arr[temp]++;
	}
	for (int i = 1; i < 10001; i++)
	{
		while (arr[i]--)
			cout << i << '\n';
	}
	return (0);
}
