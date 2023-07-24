#include <iostream>
using namespace std;

string n1, n2;
int a, b;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n1 >> n2;

	int a = (n1[2] - '0') * 100 + (n1[1] - '0') * 10 + (n1[0] - '0');
	int b = (n2[2] - '0') * 100 + (n2[1] - '0') * 10 + (n2[0] - '0');

	int ans = (a > b) ? a : b;
	cout << ans << '\n';
	return (0);
}
