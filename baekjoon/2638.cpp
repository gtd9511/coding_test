#include <iostream>
#include <queue>
using namespace std;

int map[100][100];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
int N, M;
int ans = 0;

queue<pair<int, int> > q;

void dfs(int x, int y)
{
	if (map[x][y] == 0) // 외부공기 -1, 내부공기 0, 치즈 1
		map[x][y] = -1;
	else
		return;

	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx >= 0 && nx < N && ny >= 0 && ny < M)
			dfs(nx, ny);
	}
	return ;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
			cin >> map[i][j];
	}
	dfs(0, 0);
	while (1)
	{
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				if (map[i][j] == 1)
				{
					int air = 0;
					for (int k = 0; k < 4; k++)
					{
						int nx = i + dx[k];
						int ny = j + dy[k];
						if (nx < 0 || nx >= N || ny < 0 || ny >= M)
							continue;
						if (map[nx][ny] == -1)
							air++;
					}
					if (air >= 2)
						q.push(make_pair(i, j));
				}
			}
		}
			if (q.empty())
				break;

			while (!q.empty())
			{
				int x = q.front().first;
				int y = q.front().second;
				q.pop();

				map[x][y] = -1;

				for (int i = 0; i < 4; i++)
				{
					int X = x + dx[i];
					int Y = y + dy[i];

					if (map[X][Y] == 0)
						dfs(X, Y);
				}
			}
		ans++;
	}
	cout << ans;
	return (0);
}
