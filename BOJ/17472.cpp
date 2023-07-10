#include <iostream>
#include <queue>
using namespace std;

int N, M;
int map[10][10];
bool visited[10][10];

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

void setmap()
{
	// for (int i = 0; i < N; i++)
	// {
		// for (int j = 0; j < M; j++)
			// return;
	// }
}
int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
			cin >> map[i][j];
	}

	setmap();



	return (0);
}
