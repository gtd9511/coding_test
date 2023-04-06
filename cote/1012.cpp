#include <iostream>
#include <ratio>
#include <vector>

#define MAX 50

using namespace std;

int M, N, K;
int BC[MAX][MAX];
bool visited[MAX][MAX];
int cnt;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

void reset()
{
	for (int i = 0; i < MAX; i++)
	{
		for (int j = 0; j < MAX; j++)
		{
			BC[i][j] = 0;
			visited[i][j] = 0;
		}
	}

}
void dfs(int x, int y)
{
	visited[x][y] = true;

	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (0 <= nx && nx < M && 0 <= ny && ny < N)
		{
			if (BC[nx][ny] == 1 && !visited[nx][ny])
				dfs(nx, ny);
		}
	}
}

int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		reset();
		cnt = 0;
		cin >> M >> N >> K;
		while (K--)
		{
			int a;
			int b;
			cin >> a >> b;
			BC[a][b] = 1;
		}

		for (int i = 0; i < M; i++)
		{
			for (int j = 0; j < N; j++)
			{
				if (BC[i][j] == 1 && !visited[i][j])
				{
					cnt++;
					dfs(i, j);
				}
			}
		}
		cout << cnt << endl;
	}

}
