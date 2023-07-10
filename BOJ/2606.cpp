#include <iostream>

using namespace std;

int N, M;
int arr[101][101] = {0,};
bool visited[101] = {false,};
int cnt = 0;

void dfs(int start)
{
	visited[start] = true;
	for (int i = 1; i <= N; i++)
	{
		if (arr[start][i] == 1 && !visited[i])
		{
			dfs(i);
			cnt++;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;

	for (int i = 0; i < M; i++)
	{
		int a, b;
		cin >> a >> b;
		arr[a][b] = 1;
		arr[b][a] = 1;
	}

	visited[1] = true;
	for (int i = 1; i <= N; i++)
	{
		if (arr[1][i] == 1 && !visited[i])
		{
			dfs(i);
			cnt++;
		}
	}
	cout << cnt << endl;
}
