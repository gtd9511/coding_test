#include <iostream>
#include <vector>
using namespace std;

int arr[9] = {0, 1, 2, 3, 4, 5, 6, 7, 8};
bool tile[9] = {0, };
bool temptile[9] = {0, };

int P;
int ans = 0;
int flag = 0;

void select_tile(int x)
{
	if (x == 0)
	{
		temptile[0] = !temptile[0];
		temptile[1] = !temptile[1];
		temptile[3] = !temptile[3];
		ans++;
	}
	else if (x == 1)
	{
		temptile[0] = !temptile[0];
		temptile[1] = !temptile[1];
		temptile[2] = !temptile[2];
		temptile[4] = !temptile[4];
		ans++;
	}
	else if (x == 2)
	{
		temptile[1] = !temptile[1];
		temptile[2] = !temptile[2];
		temptile[5] = !temptile[5];
		ans++;
	}
	else if (x == 3)
	{
		temptile[0] = !temptile[0];
		temptile[3] = !temptile[3];
		temptile[4] = !temptile[4];
		temptile[6] = !temptile[6];
		ans++;
	}
	else if (x == 4)
	{
		temptile[1] = !temptile[1];
		temptile[3] = !temptile[3];
		temptile[4] = !temptile[4];
		temptile[5] = !temptile[5];
		temptile[7] = !temptile[7];
		ans++;
	}
	else if (x == 5)
	{
		temptile[2] = !temptile[2];
		temptile[4] = !temptile[4];
		temptile[5] = !temptile[5];
		temptile[8] = !temptile[8];
		ans++;
	}
	else if (x == 6)
	{
		temptile[3] = !temptile[3];
		temptile[6] = !temptile[6];
		temptile[7] = !temptile[7];
		ans++;
	}
	else if (x == 7)
	{
		temptile[4] = !temptile[4];
		temptile[6] = !temptile[6];
		temptile[7] = !temptile[7];
		temptile[8] = !temptile[8];
		ans++;
	}
	else if (x == 8)
	{
		temptile[5] = !temptile[5];
		temptile[7] = !temptile[7];
		temptile[8] = !temptile[8];
		ans++;
	}
	else
		return;
}

bool is_white()
{
	for (int i = 0; i < 9; i++)
	{
		if (temptile[i] == 1)
			return (false);
	}
	return (true);
}

void perm(int n, int r, int depth)
{
	if (flag == 1)
		return ;
	ans = 0;
	if (depth == r)
	{
		for (int j = 0; j < 9; j++)
			temptile[j] = tile[j];
		// cout << "select : ";
		for (int i = 0; i < r; i++)
		{
			// cout << arr[i] << " ";
			select_tile(arr[i]);
			if (is_white())
			{
				// cout << endl << "*************" << endl;
				flag = 1;
				return ;
				// cout << ans << "\n";
				// exit(0);
			}
			// 	return ;
		}
		// cout << endl;
		// for (int i = 0; i < 9; i++)
		// {
		// 	cout << temptile[i] << " ";
		// 	if (i % 3 == 2)
		// 		cout << endl;
		// }
		// cout << endl;
		// ans += is_not_palindrome(tempstr);
		return ;
	}
	for (int i = depth; i < n; i++)
	{
		swap(arr[depth], arr[i]);
		perm(n, r, depth + 1);
		swap(arr[depth], arr[i]);
	}
}

int main()
{
	cin >> P;
	while (P--)
	{
		flag = 0;
		for (int i = 0; i < 9; i++)
		{
			char c;
			cin >> c;
			if (c == '*')
				tile[i] = 1;
			else
				tile[i] = 0;
		}
		for (int j = 0; j < 9; j++)
			temptile[j] = tile[j];
		// if (is_white())
		// {
		// 	cout << 0 << "\n";
		// 	// ans = 0;
		// 	continue ;
		// }
		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 9; j++)
				temptile[j] = tile[j];
			perm(9, i + 1, 0);
			if (flag == 1)
				break ;
		}
		// cout << "flag : " << flag << endl;
		if (flag == 0)
			cout << 0 << "\n";
		else
			cout << ans << "\n";
		// for (int i = 0; i < 9; i++)
		// {
		// 	cout << tile[i] << " ";
		// 	if (i % 3 == 2)
		// 		cout << endl;
		// }
	}
	return (0);
}

//
// ans = 0 temptile = tile
// 조합으로 확인


// 0 0 0
// 0 0 0
// 0 0 0
