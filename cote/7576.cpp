#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int map[1000][1000];
int dist[1000][1000];

queue<pair<int, int> > myqueue;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int M, N;
	cin >> M >> N;
	if (M < 2 || M > 1000 || N < 2 || N > 1000)
		return (-1);
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> map[i][j];
			if (map[i][j] == 1)
				myqueue.push(make_pair(i, j));
			if (map[i][j] == 0)
				dist[i][j] = -1;
		}
	}
	while (!myqueue.empty())
	{
		int x = myqueue.front().first;
		int y = myqueue.front().second;
		myqueue.pop();
		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || nx >= N || ny < 0 || ny >= M)
				continue;
			if (dist[nx][ny] >= 0)
				continue;
			dist[nx][ny] = dist[x][y] + 1;
			myqueue.push(make_pair(nx, ny));
		}
	}
	int ret = 0;
	for (int i = 0; i < N; i ++)
	{
		for (int j = 0; j < M; j++)
		{
			if (dist[i][j] == - 1)
			{
				cout << -1;
				return (0);
			}
			ret = max(ret, dist[i][j]);
		}
	}
	cout << ret;
	return (0);
}
