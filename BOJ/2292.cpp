#include <iostream>
using namespace std;

int N;

int main()
{
	cin >> N;
	int ans = 1;
	int temp = 1;
	while (temp < N)
	{
		temp += 6 * ans;
		ans++;
	}
	cout << ans;
	return (0);
}
