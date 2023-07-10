#include <iostream>
#include <queue>

using namespace std;

int dx[8] = {-2, -2, -1, 1, 2, 2, 1, -1};
int dy[8] = {-1, 1, 2, 2, 1, -1, -2, -2};

int map[300][300] = { 0, };
bool visited[300][300] = { false, };

struct Info
{
	int x, y, cnt;
};

Info set;
int I;

void reset()
{
	for (int i = 0; i < 300; i++)
	{
		for (int j = 0; j < 300; j++)
		{
			map[i][j] = 0;
			visited[i][j] = false;
		}
	}
	set.cnt = 0;
}

int bfs(int Sx, int Sy, int Dx, int Dy)
{
	visited[Sx][Sy] = true;
	queue<Info> myqueue;
	set.x = Sx;
	set.y = Sy;
	myqueue.push(set);

	while (!myqueue.empty())
	{
		int a = myqueue.front().x;
		int b = myqueue.front().y;
		int newcnt = myqueue.front().cnt;
		myqueue.pop();

		if (a == Dx && b == Dy)
			return newcnt;
		for (int i = 0; i < 8; i++)
		{
			int nx = a + dx[i];
			int ny = b + dy[i];

			if (0 <= nx && nx < I && 0 <= ny && ny < I && !visited[nx][ny])
			{
				visited[nx][ny] = true;
				set.x = nx;
				set.y = ny;
				set.cnt = newcnt + 1;
				myqueue.push(set);
			}
		}
	}
	return (-1);
}

int main ()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int T;
	cin >> T;
	while (T--)
	{
		reset();
		cin >> I;
		int Sx, Sy, Dx, Dy;
		cin >> Sx >> Sy >> Dx >> Dy;
		cout << bfs(Sx, Sy, Dx, Dy) << endl;
	}

	return (0);
}
