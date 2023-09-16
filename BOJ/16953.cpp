#include <iostream>
#include <deque>
using namespace std;

long long A, B, cnt = 1;

void dfs(int n)
{
	deque<pair<long long, long long> > dq;
	dq.push_back(make_pair(n, cnt));
	while (!dq.empty())
	{
		cnt = dq.front().second;

		if (2 * dq.front().first == B || dq.front().first * 10 + 1 == B)
		{
			cnt++;
			return;
		}
		if (2 * dq.front().first < 1000000000)
			dq.push_back(make_pair(2 * dq.front().first, cnt + 1));
		if (dq.front().first * 10 + 1 < 1000000000)
			dq.push_back(make_pair(dq.front().first * 10 + 1, cnt + 1));

		// for (int i = 0; i < dq.size(); i++)
			// cout << "[" << dq[i].first << ", " << dq[i].second << "] ";
		// cout << endl;
		dq.pop_front();
	}
	cnt = -1;
	return ;
}

int main()
{
	cin >> A >> B;
	dfs(A);
	cout << cnt;
	return (0);
}
