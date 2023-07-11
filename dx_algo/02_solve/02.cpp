#include <iostream>

using namespace std;

int N = 0;
int M, Q, T, ans, temp_idx;
// int A[200001] = {0, };
// int minA[200001] = {0, };
void print_map(int** A)
{
	cout << endl;
	cout << "--------------------------------" << endl;
	for (int i = 1; i < N + 1; i++)
	{
		for (int j = 1; j < M + 1; j++)
			cout << A[i][j] << " ";
		cout << endl;
	}
	cout << "--------------------------------" << endl;
	cout << endl;
}

void print_bool(bool** A)
{
	cout << endl;
	cout << "--------------------------------" << endl;
	for (int i = 1; i < N + 1; i++)
	{
		for (int j = 1; j < M + 1; j++)
			cout << A[i][j] << " ";
		cout << endl;
	}
	cout << "--------------------------------" << endl;
	cout << endl;
}

void print_check(int** check)
{
	cout << endl;
	cout << "--------------------------------" << endl;
	for (int i = 0; i < temp_idx; i++)
	{
		for (int j = 0; j < 2; j++)
			cout << check[i][j] << " ";
		cout << endl;
	}
	cout << "--------------------------------" << endl;
	cout << endl;
}

int solve(int** A, bool** flag)
{
	int min = 0;
	// A[temp_x][temp_y] = 10000001;
	// print_map(A);
	// print_bool(flag);
	// cout << "min : " << min << endl;
	// cout << "temp_x : " << temp_x << endl;
	// cout << "temp_y : " << temp_y << endl;
	// cout << "ans : " << ans << endl;
	return (min);
}

void start_flag(int** A, int** flag)
{
	for (int i = 1 ; i < N + 1; i++)
	{
		int max_x = 0;
		int temp_x = 0;
		int temp_y = 0;
		for (int j = 1; j < M + 1; j++)
		{
			if (max_x < A[i][j])
			{
				max_x = A[i][j];
				temp_x = i;
				temp_y = j;
			}
		}
		flag[temp_x][temp_y]++;
	}
	for (int i = 1; i < M + 1; i++)
	{
		int max_y = 0;
		int temp_x = 0;
		int temp_y = 0;
		for (int j = 1; j < N + 1; j++)
		{
			if (max_y < A[j][i])
			{
				max_y = A[j][i];
				temp_x = j;
				temp_y = i;
			}
		}
		flag[temp_x][temp_y]++;
	}
}
void check_max(int** A, int** flag, int** check, int x)
{
	int cur_x = check[x][0];
	int cur_y = check[x][1];
	for (int i = 1; i < N + 1; i++)
	{
	}
	for (int i = 1; i < M + 1; i++)
	{
	}
}
int each_case()
{
	ans = 0;
	int temp = 0;
	cin >> N >> M >> Q;
	// int temp = 0;
	// if (N > M)
	// 	temp = M;
	// else
	// 	temp = N;

	int** A = new int*[N + 1];
	int** flag = new int*[N + 1];
	// int** check = new int*[N + M + 1];

	for (int i = 0; i < N + 1; i++)
	{
		A[i] = new int[M + 1];
		flag[i] = new int[M + 1];
	}
	// for (int i = 0; i < temp; i++)
	// {
	// 	check[i] = new int[2];
	// 	for (int j = 0; j < 2; j++)
	// 		check[i][j] = 0;
	// }
	for (int i = 1; i < N + 1; i++)
	{
		for (int j = 1; j < M + 1; j++)
		{
			cin >> A[i][j];
			flag[i][j] = 0;
		}
	}
	start_flag(A, flag);
	// for (int i = 1 ; i < N + 1; i++)
	// {
		// for (int j = 1; j < M + 1; j++)
		// {
			// if (flag[i][j] == 2)
				// temp++;
		// }
	// }

	// temp_idx = 0;
	for (int i = 1; i < N +1; i++)
	{
		for (int j = 1; j < M + 1; j++)
		{
			if (flag[i][j] != 2)
				flag[i][j] = 0;
			else
				temp++;
			// else
			// {
				// check[temp_idx][0] = i;
				// check[temp_idx][1] = j;
				// temp_idx++;
			// }
		}
	}
	print_map(flag);
	// print_check(check);
	for (int i = 0; i < Q; i++)
	{
		int r, c, x;
		cin >> r >> c >> x;
		A[r][c] = x;
		int max_n = 0;
		for (int i = 1; i < M + 1; i++)
		{
			if (max_n < A[r][i] && flag[r][i] == 0)
				max_n = A[r][i];
			if (flag[r][i] == 2 && A[r][i] < A[r][c])
			{
				flag[r][i] = 0;
				max_n = x;
				temp--;
			}
		}
		if (max_n == x && flag[r][c] != 2)
			flag[r][c]++;
		int max_m = 0;
		for (int i = 1; i < N + 1; i++)
		{
			if (max_m < A[i][c])
				max_m = A[i][c];
			if (flag[i][c] == 2 && A[i][c] < A[r][c])
			{
				flag[i][c] = 0;
				max_m = x;
				temp--;
			}
		}
		if (max_m == x && flag[r][c] != 2)
			flag[r][c]++;
		if (flag[r][c] == 2)
			temp++;
		print_map(A);
		print_map(flag);
		cout << "temp : " << temp << endl;
		// check[temp_idx][0] = r;
		// check[temp_idx][1] = c;
		// for (int j = 0; j < temp_idx + 1; j++)
			// check_max(A, flag, check, j);
		ans += temp;
		cout << "ans : " << ans << endl;
	}
	// for (int i = 1; i < N + 1; i++)
	// {
	// 	for (int j = 1; j < M + 1; j++)
	// 	{
	// 		if (flag[i][j] == 2)
	// 			ans++;
	// 	}
	// }
	// print_map(A);
	// ans += total;

	for (int i = 0; i < N + 1; i++)
	{
		delete[] A[i];
		delete[] flag[i];
	}
	// for (int i = 0; i < temp; i++)
	// 	delete[] check[i];
	delete[] A;
	delete[] flag;
	// delete[] check;

	return (ans);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> T;
	for (int i = 1; i <= T; i++)
	{
		int ans = 0;
		ans = each_case();
		cout << "#" << i << " " << ans << endl;
	}
	return (0);
}
