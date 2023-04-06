#include <ios>
#include <iostream>
#include <queue>

using namespace std;

int map[1000][1000];
bool visited[1000][1000];

int day;

queue<pair<int, int> > myqueue;


int bfs()
{
	int ret = -1;



	return (ret);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int M, N;
	cin >> M >> N;
	if (M < 2 || M > 1000 || N < 2 || N > 1000)
		return (-1);
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> map[i][j];
			if (map[i][j] == 1)
				myqueue.push(make_pair(i, j));
		}
	}
	day = 0;
	cout << bfs() << endl;
	return (0);
}
