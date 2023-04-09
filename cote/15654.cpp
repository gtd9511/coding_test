#include <iostream>
#include <algorithm>
using namespace std;
int arr[8];
int sarr[8];
bool visited[8];

int N, M;

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
		if(!visited[i])
		{
			arr[a] = sarr[i];
			visited[i] = true;
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
	for (int i = 0; i < N; i++)
		cin >> sarr[i];
	sort(sarr, sarr + N);
	dfs(0);
	return (0);
}
