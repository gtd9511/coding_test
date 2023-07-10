#include <iostream>
#include <queue>
using namespace std;

int N, M;

int map[15][15]; // 0 길 1 베이스캠프 2편의점
bool impossible[15][15];
bool visited[15][15];
bool basecamp[15][15];

int basex[15 * 15];
int basey[15 * 15];
int cstorex[15 * 15];
int cstorey[15 * 15];

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

struct MAN
{
	int x, y, distx, disty, mtime;
};

int cal_dist(int bx, int by, int cx, int cy)
{
	int dist = abs(cx - bx) + abs(cy - by);
	return (dist);
}

int bfs()
{
	int ret = -1;

	for (int time = 0; time < M; time++)
	{
		MAN start;
		start.x = basex[time];
		start.y = basey[time];
		start.distx = cstorex[time];
		start.disty = cstorey[time];
		start.mtime = time;
		queue<MAN> myqueue;
		myqueue.push(start);
		impossible[start.x][start.y] = 1;
		while (!myqueue.empty())
		{
			MAN cur = myqueue.front();
			myqueue.pop();
			for (int i = 0; i < 4; i++)
			{
				MAN next;
				next.x = cur.x + dx[i];
				next.y = cur.y + dy[i];
				next.distx = cur.distx;
				next.disty = cur.disty;

				if (next.x < 0 || next.x >= N || next.y < 0 || next.y >= N)
					continue;
				if (impossible[next.x][next.y] == 1)
					continue;
				if (visited[next.x][next.y] == 1)
					continue;
				if (visited[next.x][next.y] == 0 && map[next.x][next.y] == 2)
				{
					impossible[next.x][next.y] = 1;
					visited[next.x][next.y] = 1;
					ret = cur.mtime + 1;
				}
				if (visited[next.x][next.y] == 0 && map[next.x][next.y] != 2)
				{
					visited[next.x][next.y] = 1;
					next.mtime = cur.mtime + 1;
					myqueue.push(next);
				}
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

	cin >> N >> M;
	if (N < 2 || N > 15 || M < 0 || M > (N ^ 2) || M > 30)
		return (-1);
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
			cin >> map[i][j];
	}
	for (int i = 0; i < M; i++)
	{
		int a;
		int b;
		cin >> a >> b;
		cstorex[i] = a;
		cstorey[i] = b;
		map[a - 1][b - 1] = 2;
		for (int j = 0; j < N; j++)
		{
			for (int k = 0; k < N; k++)
			{
				if (map[j][k] == 1)
				{
					int min = 2 * N;
					if (basecamp[j][k] == 0)
					{
						if (cal_dist(a - 1, b - 1, j, k) < min)
						{
							basex[i] = j;
							basey[i] = k;
						}
					}
				}
			}
			basecamp[basex[i]][basey[i]] = 1;
		}
	}
	cout << bfs() + 1 << endl;
	return (0);
}


/*
5 3
0 0 0 0 0
1 0 0 0 1
0 0 0 0 0
0 1 0 0 0
0 0 0 0 1
2 3
4 4
5 1
*/

/*
#include <iostream>
#include <queue>
using namespace std;

int N, M;

int map[15][15];
bool impossible[15][15];
bool visited[15][15][30];
bool basecamp[15][15];

int basex[30];
int basey[30];
int cstorex[30];
int cstorey[30];

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

int cal_dist(int bx, int by, int cx, int cy)
{
	int dist = abs(cx - bx) + abs(cy - by);
	return (dist);
}

struct MAN
{
	int x, y, distx, disty, mtime, index;
};

int bfs()
{
	int ret = -1;
	for (int time = 0; time < M; time++)
	{
	}



	int time = 0;
	MAN start;
	start.x = basex[time];
	start.y = basey[time];
	start.distx = cstorex[time];
	start.disty = cstorey[time];
	start.mtime = time;
	queue<MAN> myqueue;
	myqueue.push(start);
	impossible[start.x][start.y] = 1;
	while (!myqueue.empty())
	{
		for (int i = 1; i < M; i++)
		{
			MAN plus;
			plus.x = basex[time];
			plus.y = basey[time];
			plus.distx = cstorex[time];
			plus.disty = cstorey[time];
			start.mtime = i;
		}
	}
	return (ret);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	if (N < 2 || N > 15 || M < 0 || M > (N ^ 2) || M > 30)
		return (-1);
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
			cin >> map[i][j];
	}
	for (int i = 0; i < M; i++)
	{
		int a;
		int b;
		cin >> a >> b;
		cstorex[i] = a;
		cstorey[i] = b;
		for (int j = 0; j < N; j++)
		{
			for (int k = 0; k < N; k++)
			{
				int min = 2 * N;
				if (basecamp[j][k] == 0 && map[j][k] == 1)
				{
					if (cal_dist(a - 1, b - 1, j, k) < min)
					{
						basex[i] = j;
						basex[j] = k;
					}
					if (cal_dist(a - 1, b - 1, j, k) == min)
					{
						if (abs(a - 1 - j) < abs(a - 1 - basex[i]))
						{
							basex[i] = j;
							basey[i] = k;
						}
						if (abs(a - 1 - j) == abs(a - 1 - basex[i]))
						{
							if (k < basey[i])
							{
								basex[i] = j;
								basey[i] = k;
							}
						}
					}
				}
				cout << "a : " << a << " b : " << b << " basex : " << basex[i] << " basey : " << basey[i] << endl;
			}
		}
		basecamp[basex[i]][basey[i]] = 1;
	}
	for (int i = 0; i < M; i++)
	{
		cout << basex[i] << " " << basey[i] << endl;
	}
	//cout << bfs() + 1 << endl;
	return (0);
}
*/
