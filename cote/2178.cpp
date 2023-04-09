#include <iostream>
#include <queue>

using namespace std;

int N, M;

int map[100][100];
bool visited[100][100];

int cnt;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

struct INFO
{
	int x, y, cnt;
};

INFO start;

int bfs()
{
	int ret = -1;
	start.x = 0;
	start.y = 0;
	start.cnt = 1;
	visited[0][0] = true;
	queue<INFO> myqueue;
	myqueue.push(start);
	while (!myqueue.empty())
	{
		INFO cur = myqueue.front();
		myqueue.pop();
		if (cur.x == N - 1 && cur.y == M -1)
		{
			ret = cur.cnt;
			break;
		}
		for (int i = 0; i < 4; i++)
		{
			INFO next;
			next.x = cur.x + dx[i];
			next.y = cur.y + dy[i];
			if (next.x < 0 || next.x >= N || next.y < 0 || next.y >= M)
				continue;
			if (visited[next.x][next.y])
				continue;
			if (map[next.x][next.y] == 1 && !visited[next.x][next.y])
			{
				visited[next.x][next.y] = true;
				next.cnt = cur.cnt + 1;
				myqueue.push(next);
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

	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		string input;
		cin >> input;
		for (int j = 0; j < M; j++)
			map[i][j] = input[j] - '0';
	}

	cnt = 0;
	cout << bfs() << endl;

	return (0);
}
