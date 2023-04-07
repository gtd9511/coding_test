#include <iostream>
#include <queue>

using namespace std;

int N, M;

int map[1000][1000];
int dist[1000][1000][2];

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

struct INFO{
	int x, y, isbreak;
};

INFO start;

int bfs()
{
	queue<INFO> myqueue;
	dist[start.x][start.y][start.isbreak] = 1;
	myqueue.push(start);
	while (!myqueue.empty())
	{
		INFO cur = myqueue.front();
		myqueue.pop();
		//cout << cur.x << " " << cur.y << " " << cur.isbreak << " " << dist[cur.x][cur.y][cur.isbreak] << endl;
		if (cur.x == N - 1 && cur.y == M - 1)
			return (dist[cur.x][cur.y][cur.isbreak]);
		for (int i = 0; i < 4; i++)
		{
			INFO next;

			next.x = cur.x + dx[i];
			next.y = cur.y + dy[i];
			if (next.x < 0 || next.x >= N || next.y < 0 || next.y >= M)
				continue;
	//		if (dist[next.x][next.y][next.isbreak] == dist[cur.x][cur.y][cur.isbreak] && next.isbreak == 1)
	//			next.isbreak = 0;
			if (dist[next.x][next.y][cur.isbreak])
				continue;
			if (map[next.x][next.y] == 0)
			{
				next.isbreak = cur.isbreak;
				dist[next.x][next.y][next.isbreak] = dist[cur.x][cur.y][cur.isbreak] + 1;
				myqueue.push(next);
			}
			if (map[next.x][next.y] == 1 && cur.isbreak == 0)
			{
				next.isbreak = 1;
				dist[next.x][next.y][next.isbreak] = dist[cur.x][cur.y][cur.isbreak] + 1;
				myqueue.push(next);
			}
		}
	}
	return (-1);
}

int main()
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
			map[i][j] = input.at(j) - '0';
	}
	start.x = 0;
	start.y = 0;
	start.isbreak = 0;

	cout << bfs() << endl;
	return (0);
}
