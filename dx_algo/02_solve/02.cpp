#include <iostream>

using namespace std;

int N = 0;
int M, Q, T, ans, temp_idx;
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

int each_case()
{
	ans = 0;
	int temp = 0;
	cin >> N >> M >> Q;

	int** A = new int*[N + 1];
	int** flag = new int*[N + 1];

	for (int i = 0; i < N + 1; i++)
	{
		A[i] = new int[M + 1];
		flag[i] = new int[M + 1];
	}
	for (int i = 1; i < N + 1; i++)
	{
		for (int j = 1; j < M + 1; j++)
		{
			cin >> A[i][j];
			flag[i][j] = 0;
		}
	}
	start_flag(A, flag);
	for (int i = 1; i < N +1; i++)
	{
		for (int j = 1; j < M + 1; j++)
		{
			if (flag[i][j] != 2)
				flag[i][j] = 0;
			else
				temp++;
		}
	}
	cout << "****0****" << endl;
	print_map(A);
	print_map(flag);
	for (int i = 0; i < Q; i++)
	{
		cout << "****" << i + 1 << "****" << endl;
		int r, c, x;
		cin >> r >> c >> x;
		A[r][c] = x;
		int max_n = 0;
		if (flag[r][c] != 2)
		{
			for (int i = 1; i < M + 1; i++)
			{
				if (flag[r][i] == 2 && A[r][c] > A[r][i])
				{
					cout << "----------------------------------" << endl;
					flag[r][i] = 0;
					max_n = x;
					temp--;
					break;
				}
				if (flag[r][i] == 2 && A[r][c] < A[r][i])
					break;
				if (max_n < A[r][i] && flag[r][i] != 2)
					max_n = A[r][i];
			}
			int max_m = 0;
			for (int i = 1; i < N + 1; i++)
			{
				if (flag[i][c] == 2 && A[r][c] > A[i][c])
				{
					cout << "====================================" << endl;
					flag[i][c] = 0;
					max_m = x;
					temp--;
					break;
				}
				if (flag[i][c] == 2 && A[r][c] < A[i][c])
					break;
				if (max_m < A[i][c] && flag[i][c] != 2)
					max_m = A[i][c];
			}
			if (max_n == x && max_m == x)
			{
				flag[r][c] = 2;
				temp++;
			}
		}
		print_map(A);
		print_map(flag);
		cout << "temp : " << temp << endl;
		ans += temp;
		cout << "ans : " << ans << endl;
	}
	// print_map(A);

	for (int i = 0; i < N + 1; i++)
	{
		delete[] A[i];
		delete[] flag[i];
	}
	delete[] A;
	delete[] flag;

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
		cout << "#" << i << " " << ans << "\n";
	}
	return (0);
}
