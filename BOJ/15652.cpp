#include <iostream>
using namespace std;

int arr[7] = { 0, };
//bool visited[7] = { 0, };

int N, M;

void dfs(int num, int a)
{
	if (a == M)
	{
		for (int i = 0; i < M; i++)
			cout << arr[i] << ' ';
		cout << '\n';
		return ;
	}
	for (int i = num; i < N; i++)
	{
		arr[a] = i + 1;
		//visited[i] = true;
		dfs(i , a + 1);
		//visited[i] = false;
	}
}
int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> M;
	dfs(0, 0);
	return (0);
}
