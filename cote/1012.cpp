#include <iostream>
#include <typeinfo>
#include <vector>
#include <queue>

using namespace std;

int bfs()
{
	bool visited[50][50] = { false };
	queue<pair<int, int> > muqueue;
//	visited[x][y] = true;
}

int main ()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int T;
	while (T--)
	{
		int M, N, K;
		int field[50][50] = { 0 };
		cin >> M >> N >> K;
		while (K--)
		{
			int x;
			int y;
			cin >> x >> y;
			field[x][y] = 1;
		}

	}


	return (0);
}
