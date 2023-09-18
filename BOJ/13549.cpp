#include <iostream>
#include <queue>
using namespace std;

int N, K, ans = 0;
bool visited[100001] = {0, };

void dfs(int n, int k)
{
	queue<pair<int, int> > q;
	q.push(make_pair(n, 0));
	visited[n] = true;
	while (!q.empty())
	{
		int top_f = q.front().first;
		int top_s = q.front().second;
		q.pop();
		// cout << top_f << " " << top_s << endl;
		if (top_f == k)
		{
			ans = top_s;
			break ;
		}
		if (2 * top_f <= 100000)
		{
			if (visited[2 * top_f] == false)
			{
				q.push(make_pair(2 * top_f, top_s));
				visited[2 * top_f] = true;
			}
		}
		if (top_f - 1 >= 0)
		{
			if(visited[top_f - 1] == false)
			{
				q.push(make_pair(top_f - 1, top_s + 1));
				visited[top_f - 1] = true;
			}
		}
		if (top_f + 1 <= 100000)
		{
			if (visited[top_f + 1] == false)
			{
				q.push(make_pair(top_f + 1, top_s + 1));
				visited[top_f + 1] = true;
			}
		}
	}
	return ;
}

int main()
{
	cin >> N >> K;
	dfs(N, K);
	cout << ans;
	return (0);
}
