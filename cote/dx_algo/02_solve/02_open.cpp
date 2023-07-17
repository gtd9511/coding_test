#include <iostream>
#include <algorithm>
#include <iterator>

using namespace std;

int N, M, Q, T, ans;

void start_flag(int** A, int* max_list)
{
	for (int i = 1 ; i < N + 1; i++)
	{
		int max_x = 0;
		for (int j = 1; j < M + 1; j++)
		{
			if (max_x < A[i][j])
				max_x = A[i][j];
		}
		max_list[i] = max_x;
	}
	for (int i = 1; i < M + 1; i++)
	{
		int max_y = 0;
		for (int j = 1; j < N + 1; j++)
		{
			if (max_y < A[j][i])
				max_y = A[j][i];
		}
		max_list[i + N] = max_y;
	}
}

int count_common(int max_list[])
{
	int cnt = 0;
	for (int i = 0; i < N + M + 1; i++)
	{
		if (arr[max_list[i]] > 0)
		{
			arr[max_list[i]]++;
			if (arr[max_list[i]] == 2)
				cnt++;
		}
	}
	return (cnt);
}

int each_case(int N, int M, int Q)
{
	ans = 0;
	int temp = 0;

	int* max_list = new int[N + M + 1];
	int* temp_list = new int[N + M + 1];
	int** A = new int*[N + 1];
	for (int i = 0; i < N + 1; i++)
		A[i] = new int[M + 1];
	for (int i = 1; i < N + 1; i++)
	{
		for (int j = 1; j < M + 1; j++)
			cin >> A[i][j];
	}
	for (int i = 0; i < N + M + 1; i++)
		max_list[i] = 0;
	start_flag(A, max_list);
	copy_n(max_list, temp_list, N + M + 1);
	sort(temp_list, temp_list + N + M + 1);
	

	for (int i = 0; i < Q; i++)
	{
		temp = 0;
		int r, c, x;
		cin >> r >> c >> x;
		A[r][c] = x;
		if (max_list[r] < x)
			max_list[r] = x;
		if (max_list[c + N] < x)
			max_list[c + N] = x;
		temp += count_common(max_list);
		ans += temp;
	}

	for (int i = 0; i < N + 1; i++)
		delete[] A[i];
	delete[] A;
	delete[] max_list;
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
