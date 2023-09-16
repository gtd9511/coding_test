#include <iostream>
#include <deque>
using namespace std;

int A, B, cnt = 1;

void dfs(int n)
{
	deque<int> dq;
	dq.push_back(n);
	while (!dq.empty())
	{
		if (2 * dq.front() == B || dq.front() * 10 + 1 == B)
			return;
		if (2 * dq.front() < B )
			dq.push_back(2 * dq.front());
		if (dq.front() * 10 + 1 < B)
			dq.push_back(dq.front() * 10 + 1);
		
		for (int i = 0; i < dq.size(); i++)
			cout << dq.front() << " ";
		cout << endl;
		dq.pop_front();
		cnt ++;
	}
	return ;
}

int main()
{
	cin >> A >> B;
	dfs(A);
	cout << cnt;
}
