#include <iostream>
#include <queue>
using namespace std;

int N, K, ans, cnt = 0;
bool visited[100001];

void bfs(int n, int k)
{
	queue<pair<int, int> > q;
	q.push(make_pair(n, 0));
	visited[n] = true;
	while (!q.empty())
	{
		int top_f = q.front().first;
		int top_s = q.front().second;
		q.pop();
		visited[top_f] = true;
		// cout << top_f << " " << top_s << endl;
		if (ans && top_f == k && ans == top_s)
			cnt++;
		if (!ans && top_f == k)
		{
			ans = top_s;
			cnt++;
		}
		if (2 * top_f <= 100000 && !visited[2 * top_f])
			q.push(make_pair(2 * top_f, top_s + 1));
		if (top_f - 1 >= 0 && !visited[top_f - 1])
			q.push(make_pair(top_f - 1, top_s + 1));
		if (top_f + 1 <= 100000 && !visited[top_f + 1])
			q.push(make_pair(top_f + 1, top_s + 1));
	}
	return ;
}

int main()
{
	cin >> N >> K;
	bfs(N, K);
	cout << ans << "\n" << cnt;
	return (0);
}
