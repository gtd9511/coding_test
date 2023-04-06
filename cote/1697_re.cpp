#include <iostream>
#include <queue>

using namespace std;

bool visited[100001] = { false, };

int bfs(int N, int K)
{
	int cnt = 0;
	visited[N] = true;
	queue<pair<int, int> > myqueue;
	myqueue.push(make_pair(N, cnt));
	while (!myqueue.empty())
	{
		N = myqueue.front().first;
		cnt = myqueue.front().second;
		myqueue.pop();
		if (N == K)
			return (cnt);
		if (N + 1 >= 0 && N + 1 < 100001 && !visited[N + 1])
		{
			visited[N + 1] = true;
			myqueue.push(make_pair(N + 1, cnt + 1));
		}
		if (N - 1 >= 0 && N - 1 < 100001 && !visited[N - 1])
		{
			visited[N - 1] = true;
			myqueue.push(make_pair(N - 1, cnt + 1));
		}
		if (N * 2 >= 0 && N * 2 < 100001 && !visited[N * 2])
		{
			visited[N * 2] = true;
			myqueue.push(make_pair(N * 2, cnt + 1));
		}
	}
		return (-1);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N, K;
	cin >> N >> K;
	cout << bfs(N, K) << endl;
	return (0);
}
