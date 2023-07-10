#include <iostream>
#include <queue>

using namespace std;

char map[10][10];
bool visited[10][10][10][10] = { false, };

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

struct INFO
{
	int rx, ry, bx, by, cnt;
};

INFO start;

int bfs()
{
	int ret = -1;
	queue<INFO> myqueue;
	myqueue.push(start);
	visited[start.rx][start.ry][start.bx][start.by] = true;
	while (!myqueue.empty())
	{
		INFO cur;
		cur = myqueue.front();
		myqueue.pop();
		if (cur.cnt > 10)
			return (-1);
		if (map[cur.rx][cur.ry] == 'O' && map[cur.bx][cur.by] != 'O')
			return (cur.cnt);
		for (int i = 0; i < 4; i++)
		{
			int nrx = cur.rx;
			int nry = cur.ry;
			int nbx = cur.bx;
			int nby = cur.by;

			while (1)
			{
				if (map[nrx][nry] != '#' && map[nrx][nry] != 'O')
				{
					nrx += dx[i];
					nry += dy[i];
				}
				else
				{
					if (map[nrx][nry] == '#')
					{
						nrx -= dx[i];
						nry -= dy[i];
					}
					break;
				}
			}
			while (1)
			{
				if (map[nbx][nby] != '#' && map[nbx][nby] != 'O')
				{
					nbx += dx[i];
					nby += dy[i];
				}
				else
				{
					if (map[nbx][nby] == '#')
					{
						nbx -= dx[i];
						nby -= dy[i];
					}
					break;
				}
			}

			if (nrx == nbx && nry == nby)
			{
				if (map[nrx][nry] != 'O')
				{
					if (i == 0 || i == 2)
					{
						if (abs(nrx - cur.rx) > abs(nbx - cur.bx))
							nrx -= dx[i];
						else
						 	nbx -= dx[i];
					}
					if (i == 1 || i == 3)
					{
						if (abs(nry - cur.ry) > abs(nby - cur.by))
							nry -= dy[i];
						else
						 	nby -= dy[i];
					}
				}
			}


			if (visited[nrx][nry][nbx][nby] == false)
			{
				visited[nrx][nry][nbx][nby] = true;
				INFO next;
				next.rx = nrx;
				next.ry = nry;
				next.bx = nbx;
				next.by = nby;
				next.cnt = cur.cnt + 1;
				myqueue.push(next);
			}
		}
	}
	return (ret);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	cin >> N >> M;
	if (N < 3 || N > 11 || M < 3 || M > 11)
		return (-1);

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> map[i][j];
			if (map[i][j] == 'R')
			{
				start.rx = i;
				start.ry = j;
			}
			if (map[i][j] == 'B')
			{
				start.bx = i;
				start.by = j;
			}
		}
	}
	start.cnt = 0;

	cout << bfs() << endl;
	return (0);
}
