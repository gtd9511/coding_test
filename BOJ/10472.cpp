#include <iostream>
#include <queue>
using namespace std;

bool arr[3][3];
bool visited[3][3];
int P;
int cnt;
int ans;

void select_tile(int x, int y)
{
	arr[x][y] = !arr[x][y];
	if (x - 1 >= 0)
		arr[x - 1][y] = !arr[x - 1][y];
	if (x + 1 < 3)
		arr[x + 1][y] = !arr[x + 1][y];
	if (y - 1 >= 0)
		arr[x][y - 1] = !arr[x][y - 1];
	if (y + 1 < 3)
		arr[x][y + 1] = !arr[x][y + 1];
	cnt++;
}

bool is_white()
{
	bool flag = false;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (arr[i][j])
			{
				flag = true;
				break;
			}
		}
	}
	return flag;
}

int main()
{
	cin >> P;
	while (P--)
	{
		ans = 0;
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				char temp;
				cin >> temp;
				if (temp == '*')
					arr[i][j] = true;
				if (temp == '.')
					arr[i][j] = false;
			}
		}
		while (is_white())
		{
			cnt = 0;

		}
		cout << ans << endl;
	}
	return (0);
}
