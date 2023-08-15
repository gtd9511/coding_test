#include <iostream>
#include <queue>

using namespace std;

int N, M;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
char map[50][50];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			char temp;
			cin >> temp;
			map[i][j] = temp;
		}
	}

	return (0);
}
