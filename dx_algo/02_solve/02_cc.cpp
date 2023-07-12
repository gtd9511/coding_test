#include <iostream>
#include <algorithm>
#include <iterator>
using namespace std;

int N, M, Q, T, ans, temp_idx;

void start_flag(int** A, int* ns_list, int* we_list)
{
	for (int i = 1 ; i < N + 1; i++)
	{
		int max_x = 0;
		for (int j = 1; j < M + 1; j++)
		{
			if (max_x < A[i][j])
				max_x = A[i][j];
		}
		ns_list[i] = max_x;
	}
	for (int i = 1; i < M + 1; i++)
	{
		int max_y = 0;
		for (int j = 1; j < N + 1; j++)
		{
			if (max_y < A[j][i])
				max_y = A[j][i];
		}
		we_list[i] = max_y;
	}
}

int each_case(int N, int M, int Q)
{
	ans = 0;
	int temp = 0;

	int** A = new int*[N + 1];
	int* ns_list = new int[N + 1];
	int* we_list = new int[M + 1];
	for (int i = 0; i < N + 1; i++)
		A[i] = new int[M + 1];
	for (int i = 1; i < N + 1; i++)
	{
		for (int j = 1; j < M + 1; j++)
			cin >> A[i][j];
	}
	start_flag(A, ns_list, we_list);

	for (int i = 0; i < Q; i++)
	{
		temp = 1;
		int r, c, x;
		cin >> r >> c >> x;
		A[r][c] = x;
		if (ns_list[r] < x)
			ns_list[r] = x;
		if (we_list[c] < x)
			we_list[c] = x;
		int* temp_ns = new int [N + 1];
		int* temp_we = new int [M + 1];
		copy_n(ns_list, N + 1, temp_ns);
		copy_n(we_list, M + 1, temp_we);
		sort(temp_ns + 1, temp_ns + N + 1);
		sort(temp_we + 1, temp_we + M + 1);
		int a = 1;
		int b = 1;
		while (a < N && b < M)
		{
			if (temp_ns[a] == temp_we[b])
			{
				a++;
				b++;
				temp++;
			}
			else if (temp_ns[a] < temp_we[b])
				a++;
			else
				b++;
		}
		ans += temp;
	}

	for (int i = 0; i < N + 1; i++)
		delete[] A[i];
	delete[] A;
	delete[] ns_list;
	delete[] we_list;
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
		cin >> N >> M >> Q;
		int ans = each_case(N, M, Q);
		cout << "#" << i << " " << ans << endl;
	}
	return (0);
}
