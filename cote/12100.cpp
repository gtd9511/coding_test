#include <iostream>

using namespace std;


int N;
int board[20][20];

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

int result;

void dfs()
{
	
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
			cin >> board[i][j];
	}

	result = 0;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (result < board[i][j])
				result = board[i][j];
		}
	}


	cout << result << endl;
	return (0);
}
