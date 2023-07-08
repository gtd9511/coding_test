#include <iostream>
#include <queue>
using namespace std;

int map[101][101] = { 0, };

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, K, L;
	int time = 0;
	cin >> N >> K;
	for (int i = 0; i < K; i++)
	{
		int a;
		int b;
		cin >> a >> b;
		map[a][b] = 1;
	}
	cin >> L;

	queue<pair<int, int> > snack;
	snack.push(make_pair(0, 0));
	for (int i = 0; i < L; i++)
	{
		int a;
		char b;
		cin >> a >> b;
		while (a--)
		{
			if (map[])

		}
		if (i == L - 1)
		{

		}
	}

}
