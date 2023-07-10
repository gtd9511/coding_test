#include <iostream>
#include <queue>
using namespace std;

int N, L, R;
int map[50][50];
bool visited[50][50];
int dx[4] = {-1, 0, 1, 0}; // 북 동 남 서
int dy[4] = {0, 1, 0, -1};

void bfs(int x, int y)
{
	queue<pair<int, int> > q;
	q.push(make_pair(x, y));
	visited[x][y] = true;

	while (!q.empty())
	{
		int cur_x = q.front().first;
		int cur_y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int next_x = cur_x + dx[i];
			int next_y = cur_y + dy[i];

			if (next_x < 0 || next_x >= N || next_y < 0 || next_y >= N)
				continue;
			if (visited[next_x][next_y])
				continue;
			if (abs(map[cur_x][cur_y] - map[next_x][next_y]) < L || abs(map[cur_x][cur_y] - map[next_x][next_y]) > R)
				continue;
			visited[next_x][next_y] = true;
			q.push(make_pair(next_x, next_y));
		}
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> L >> R;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++) // 1. 모든 칸에 대해
			cin >> map[i][j];
	}


	return (0);
}

