#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int bfs(int N, int K, int cnt)
{
	bool visited[100001] = { false };
	queue<pair<int, int> > myqueue;
	visited[N] = true;
	myqueue.push(make_pair(N, 0));
	while (!myqueue.empty())
	{
		N = myqueue.front().first;
		cnt = myqueue.front().second;
		//cout << "T : " << N << " cnt : " << cnt << endl;
		myqueue.pop();
		if (N == K)
			return cnt;
		if (N + 1 >= 0 && N + 1 <= 100000)
		{
			if (!visited[N + 1])
			{
				visited[N + 1] = true;
				myqueue.push(make_pair(N + 1, cnt + 1));
			}
		}
		if (N - 1 >= 0 && N - 1 <= 100000)
		{
			if (!visited[N - 1])
			{
				visited[N - 1] = true;
				myqueue.push(make_pair(N - 1, cnt + 1));
			}
		}
		if (N * 2 >= 0 && N * 2 <= 100000)
		{
			if (!visited[2 * N])
			{
				visited[2 * N] = true;
				myqueue.push(make_pair(2 * N, cnt + 1));
			}
		}
	}
	return -1;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N;
	int K;
	cin >> N >> K;
	int cnt = 0;
	cout << bfs(N, K, cnt) << endl;
}
