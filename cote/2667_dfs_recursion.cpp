
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

int n ;
int group_id;
int groups[25 * 25];

int map[25][25];
bool visited [25][25] = { false, };


void dfs(int x, int y)
{
	visited[x][y] = true;

	groups[group_id]++;
	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (0 <= nx && nx < n && 0 <= ny && ny < n)
		{
			if (map[nx][ny] == 1 && !visited[nx][ny])
				dfs(nx, ny);
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	if (n > 25 || n < 5)
		return (-1);


	for (int i = 0; i < n; i++)
	{
		string input;
		cin >> input;
		for (int j = 0; j < n; j++)
			map[i][j] = input.at(j) - '0';
	}

	for (int i = 0; i< n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (map[i][j] == 1 && visited[i][j] == false)
			{
				group_id++;
				dfs(i, j);
			}
		}
	}

	sort(groups + 1, groups + group_id + 1);

	cout << group_id << endl;
	for (int i = 1; i <= group_id; i++)
		cout << groups[i] << endl;
	return (0);

}
