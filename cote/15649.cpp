#include <iostream>
using namespace std;

int N, M;
int arr[8] = { 0, };
bool visited[8] = { 0, };

void dfs(int a)
{
	if (a == M)
	{
		for (int i = 0; i < M; i++)
			cout << arr[i] << ' ';
		cout << '\n';
		return ;
	}
	for (int i = 0; i < N; i++)
	{
		if (!visited[i])
		{
			visited[i] = true;
			arr[a] = i + 1;
			dfs(a + 1);
			visited[i] = false;
		}
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	dfs(0);
	return (0);
}
