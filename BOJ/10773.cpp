#include <iostream>
#include <stack>
using namespace std;

int K;
int ans = 0;
stack<int> s;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> K;
	while (K--)
	{
		int temp;
		cin >> temp;
		if (temp > 0)
			s.push(temp);
		else if (temp == 0)
			s.pop();
	}
	while (!s.empty())
	{
		ans += s.top();
		s.pop();
	}
	cout << ans;
	return (0);
}
