#include <iostream>
using namespace std;

int map[100][100];
int tmp[100][100];
bool visited[100][100];
int air[100][100] = {
	0,
};
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
int N, M;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> map[i][j];
			tmp[i][j] = map[i][j];
		}
	}
	int cnt = 0;

	while (1)
	{
		int flag = 0;
		for (int i = 0; i < N; i++)
			for (int j = 0; j < M; j++)
			{
				if (map[i][j] == 1)
				{
					flag = 1;
					int air = 0;
					for (int k = 0; k < 4; k++)
					{
						int nx = i + dx[k];
						int ny = j + dy[k];
						if (nx < 0 || nx >= N || ny < 0 || ny >= M)
							continue;
						if (map[nx][ny] == 0)
							air++;
					}
					if (air >= 2)
						tmp[i][j] = 0;
				}
			}
		if (flag == 0)
			break;
		cnt++;
		for (int i = 0; i < N; i++)
			for (int j = 0; j < M; j++)
				map[i][j] = tmp[i][j];
	}
	cout << cnt;
	return (0);
}
