#include <iostream>
using namespace std;

int N;

int main()
{
	cin >> N;
	int ans = 2;
	for (int i = 0; i < N; i++)
		ans = ans * 2 - 1;
	cout << ans * ans;
	return (0);
}
