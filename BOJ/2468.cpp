#include <cstdlib>
#include <iostream>
#include <mutex>
#include <queue>

using namespace std;

int N;
int map[100][100];
bool visited[100][100];

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

int bfs(int x, int y, int R)
{
	int ret = 1;
	visited[x][y] = true;
	queue<pair<int, int> > myqueue;
	myqueue.push(make_pair(x, y));
	while (!myqueue.empty())
	{
		int curx = myqueue.front().first;
		int cury = myqueue.front().second;
		myqueue.pop();
		for (int i = 0; i < 4; i++)
		{
			int nx = curx + dx[i];
			int ny = cury + dy[i];
			if (nx < 0 || nx >= N || ny < 0 || ny >= N)
				continue;
			if (visited[nx][ny] || map[nx][ny] <= R)
				continue;
			if (map[nx][ny] > R && !visited[nx][ny])
			{
				visited[nx][ny] = true;
				myqueue.push(make_pair(nx, ny));
			}
		}
	}
	return (ret);
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	int ground[100] = { 0, };

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> map[i][j];
			//if (map[i][j] <= a)
			//	visited[i][j] = true;
		}
	}
	for (int a = 0; a < 100; a++)
	{
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				if (!visited[i][j] && map[i][j] > a)
					ground[a] += bfs(i, j, a);
			}
		}
		for (int i = 0; i < 100; i++)
		{
			for (int j = 0; j < 100; j++)
			{
				visited[i][j] = false;
			}
		}
	}
	int max = 0;
	for (int i = 0; i < 100; i++)
	{
		if (max < ground[i])
			max = ground[i];
		//cout << ground[i] << " ";
	}
	cout << max << endl;
	return (0);
}
