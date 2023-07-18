#include <iostream>
#include <queue>
#include <utility>
using namespace std;

bool arr[3][3];
bool temparr[3][3];
bool visited[3][3];
int minarr[9] = {0, };
int P;
int ans;
int cnt = 0;

void select_tile(int x, int y)
{
	temparr[x][y] = !temparr[x][y];
	if (x - 1 >= 0)
		temparr[x - 1][y] = !temparr[x - 1][y];
	if (x + 1 < 3)
		temparr[x + 1][y] = !temparr[x + 1][y];
	if (y - 1 >= 0)
		temparr[x][y - 1] = !temparr[x][y - 1];
	if (y + 1 < 3)
		temparr[x][y + 1] = !temparr[x][y + 1];
	cnt++;
}

bool is_white()
{
	bool flag = false;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (temparr[i][j])
			{
				flag = true;
				break;
			}
		}
	}
	return flag;
}

int bfs(int x, int y)
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			temparr[i][j] = arr[i][j];
			visited[i][j] = false;
			// cout << temparr[i][j] << " ";
		}
		// cout << endl;
	}
	select_tile(x, y);
	if (!is_white())
	{
		// cout << 3 * x + y << " : " << cnt <<  endl;
		return (cnt);
	}
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cout << temparr[i][j] << " ";
		}
		cout << endl;
	}
	queue<pair<int, int> > q;
	q.push(make_pair(x, y));
	visited[x][y] = true;
	while (!q.empty())
	{
		int cur_x = q.front().first;
		int cur_y = q.front().second;
		cout << "cur_x : " << cur_x << " cur_y : " << cur_y << endl;
		q.pop();
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				if (i != cur_x && j != cur_y)
				{
					q.push(make_pair(i, j));
					visited[i][j] = true;
					select_tile(i, j);
					if (!is_white() || cnt > 8)
						return (cnt);
				}
			}
		}
	}
	cnt = 100;
	return (cnt);
}

int main()
{
	cin >> P;
	while (P--)
	{
		ans = 2147483647;
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				char temp;
				cin >> temp;
				if (temp == '*')
					arr[i][j] = true;
				if (temp == '.')
					arr[i][j] = false;
				minarr[3 * i + j] = 0;
			}
		}
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				cnt = 0;
				minarr[3 * i + j] = bfs(i, j);
				cout << 3 * i + j << " : " << minarr[3 * i + j] << endl;
			}
		}
		for (int i = 0; i < 9; i++)
		{
			cout << minarr[i] << " ";
			if (ans > minarr[i] && minarr[i] > 0)
				ans = minarr[i];
		}
		cout << " ans : " << ans << endl;
	}
	return (0);
}
