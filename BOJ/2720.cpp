#include <iostream>
using namespace std;

int N, M;
int ans[4];

int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> M;
	 	ans[0] = M / 25;
		ans[1] = (M % 25) / 10;
		ans[2] = ((M % 25) % 10) / 5;
		ans[3] = M % 5;
		for (int j = 0; j < 4; j++)
			cout << ans[j] << " ";
		cout << '\n';
	}
	return (0);
}
