#include <iostream>
using namespace std;

int cube[6] = {0,};
int map[20][20];
int order[1000] = {0, };
int N, M, cx, cy, K;

// void show_cube(int x, int y)
// {
	// for (int i = 0; i < 6; i++)
		// cout << cube[i] << " ";
	// cout << "X : " << x << " Y : " << y << endl;
// }

void move_s(int x, int y)
{
	int temp = cube[5];
	if (map[x][y] == 0)
	{
		map[x][y] = cube[4];
		cube[5] = cube[4];
	}
	else
	{
	 	cube[5] = map[x][y];
		map[x][y] = 0;
	}
	cube[4] = cube[0];
	cube[0] = cube[1];
	cube[1] = temp;
}

void move_n(int x, int y)
{
	int temp = cube[5];
	if (map[x][y] == 0)
	{
		map[x][y] = cube[1];
		cube[5] = cube[1];
	}
	else
	{
	 	cube[5] = map[x][y];
		map[x][y] = 0;
	}
	cube[1] = cube[0];
	cube[0] = cube[4];
	cube[4] = temp;
}
void move_e(int x, int y)
{
	int temp = cube[5];
	if (map[x][y] == 0)
	{
		map[x][y] = cube[2];
		cube[5] = cube[2];
	}
	else
	{
	 	cube[5] = map[x][y];
		map[x][y] = 0;
	}
	cube[2] = cube[0];
	cube[0] = cube[3];
	cube[3] = temp;
}
void move_w(int x, int y)
{
	int temp = cube[5];
	if (map[x][y] == 0)
	{
		map[x][y] = cube[3];
		cube[5] = cube[3];
	}
	else
	{
	 	cube[5] = map[x][y];
		map[x][y] = 0;
	}
	cube[3] = cube[0];
	cube[0] = cube[2];
	cube[2] = temp;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M >> cx >> cy >> K;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j< M; j++)
			cin >> map[i][j];
	}

	for (int i = 0; i < K; i++)
	{
		cin >> order[i];
		if (order[i] == 1)
		{
			int nx = cx;
			int ny = cy + 1;
			if (ny >= 0 && ny < M)
			{
				move_e(nx, ny);
				//show_cube(nx, ny);
				cout << cube[0];// << endl;
				cx = nx;
				cy = ny;
			}
		}
		if (order[i] == 2)
		{
			int nx = cx;
			int ny = cy - 1;
			if (ny >= 0 && ny < M)
			{
				move_w(nx, ny);
				//show_cube(nx, ny);
				cout << cube[0];// << endl;
				cx = nx;
				cy = ny;
			}
		}
		if (order[i] == 3)
		{
			int nx = cx - 1;
			int ny = cy;
			if (nx >= 0 && nx < N)
			{
				move_n(nx, ny);
				//show_cube(nx, ny);
				cout << cube[0];// << endl;
				cx = nx;
				cy = ny;
			}
		}
		if (order[i] == 4)
		{
			int nx = cx + 1;
			int ny = cy;
			if (nx >= 0 && nx < N)
			{
				move_s(nx, ny);
				//show_cube(nx, ny);
				cout << cube[0];// << endl;
				cx = nx;
				cy = ny;
			}
		}
	}
	return (0);
}
