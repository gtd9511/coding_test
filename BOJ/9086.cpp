#include <iostream>
using namespace std;

int N;
string str;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> str;
		cout << str[0] << str[str.length() - 1] << '\n';
	}
	return (0);
}
