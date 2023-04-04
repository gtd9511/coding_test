1
#include <iostream>
// #include <vector>
// #include <queue>
// #include <algorithm>

using namespace std;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

int N;
int group_id;
int groups[25*25];

int map[25][25];
bool visited[25][25];

void dfs_recursion(int x, int y)
{
	visited[x][y] = true;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	return (0);
}
