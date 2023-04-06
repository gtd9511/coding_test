#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
#define MAX 25

int N;
int groups[MAX * MAX];
int group_id;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

int map[MAX][MAX];
bool visited[MAX][MAX] = { false, };

void bfs(int x, int y)
{
	queue<pair<int, int> > myqueue;
	visited[x][y] = true;

	myqueue.push(make_pair(x, y));
	groups[group_id]++;

	while(!myqueue.empty())
	{
		x = myqueue.front().first;
		y = myqueue.front().second;
		myqueue.pop();

		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (0 <= nx && nx < N && 0 <= ny && ny < N)
			{
				if (map[nx][ny] == 1 && !visited[nx][ny])
				{
					visited[nx][ny] = true;
					groups[group_id]++;

					myqueue.push(make_pair(nx, ny));
				}
			}
		}
	}

}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		string input;
		cin >> input;
		for (int j = 0; j < N; j++)
			map[i][j] = input.at(j) - '0';
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (map[i][j] == 1 && !visited[i][j])
			{
				group_id++;
				bfs(i, j);
			}

		}
	}

	cout << group_id << endl;
	sort(groups + 1, groups + group_id + 1);
	for (int i = 1; i <= group_id; i++)
		cout << groups[i] << endl;
	return (0);
}

