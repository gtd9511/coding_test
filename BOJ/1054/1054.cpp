#include <iostream>
using namespace std;

int arr[25] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24};
string str[25];
// bool flag[25] = {0, };
int ans = 0;
int cnt = 0;

int is_palindrome(string str)
{
	int len = str.length();
	for (int i = 0; i < len / 2; i++)
	{
		if (str[i] != str[len - i - 1])
			return (0);
	}
	return (1);
}

int is_not_palindrome(string str)
{
	int len = str.length();
	for (int i = 0; i < len / 2; i++)
	{
		if (str[i] != str[len - i - 1])
			return (1);
	}
	return (0);
}

void perm(int n, int r, int depth)
{
	string tempstr = "";
	if (depth == r)
	{
		for (int i = 0; i < r; i++)
		{
			tempstr.append(str[arr[i]]);
			// cout << arr[i] << " ";
		}
		cnt++;
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
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> str[i];
		// flag[i] = true;
	}
	for (int i = 0; i < N; i++)
	{
		perm(N, i + 1, 0);
		// cout << "i : " << cnt << endl;
	}
	cout << ans << "\n";
	cout << "cnt : " << cnt << endl;
	cout << cnt - ans << endl;
	return (0);
}
//8877 6910
//ab ba
//abba baab
//a ab
//aba
