#include <iostream>
#include <algorithm>
#include <iterator>
#include <unordered_set>
using namespace std;

int N, M, Q, T, ans, temp_idx;
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

int count_common(int arr1[], int size1, int arr2[], int size2)
{
	std::unordered_set<int> set1;

	for (int i = 0; i < size1; i++)
		set1.insert(arr1[i]);

	int cnt = 0;

	for (int i = 0; i < size2; i++)
	{
		if (set1.find(arr2[i]) != set1.end())
		{
			cnt++;
			set1.erase(arr2[i]);
		}
	}
	// cout << "cnt : " << cnt << endl;
	return (cnt - 1);
}

int each_case(int N, int M, int Q)
{
	ans = 0;
	int temp = 0;

	int** A = new int*[N + 1];
	int* ns_list = new int[N + 1];
	int* we_list = new int[M + 1];
	// int ns_list[200001] = {0, };
	// int we_list[200001] = {0, };
	for (int i = 0; i < N + 1; i++)
	// {
		A[i] = new int[M + 1];
		// ns_list[i] = 0;
	// }
	// for (int i = 0; i < M + 1; i++)
		// we_list[i] = 0;
	for (int i = 1; i < N + 1; i++)
	{
		for (int j = 1; j < M + 1; j++)
			cin >> A[i][j];
	}
	ns_list[0] = 0;
	we_list[0] = 0;
	start_flag(A, ns_list, we_list);

	// cout << "****0****" << endl;
	// print_map(A);
	// print_map(flag);

	for (int i = 0; i < Q; i++)
	{
		temp = 0;
		// cout << "****" << i + 1 << "****" << endl;
		int r, c, x;
		cin >> r >> c >> x;
		A[r][c] = x;
		if (ns_list[r] < x)
			ns_list[r] = x;
		if (we_list[c] < x)
			we_list[c] = x;

		// for (int i = 0; i < N + 1; i++)
		// 	cout << ns_list[i] << " ";
		// cout << endl;
		// for (int i = 0; i < M + 1; i++)
		// 	cout << we_list[i] << " ";
		// cout << endl;
		temp += count_common(ns_list, N + 1, we_list, M + 1);
		// cout << "temp : " << temp << endl;
		// int* temp_ns = new int [N + 1];
		// int* temp_we = new int [M + 1];
		// copy_n(ns_list, N + 1, temp_ns);
		// copy_n(we_list, M + 1, temp_we);
		// sort(temp_ns + 1, temp_ns + N + 1);
		// sort(temp_we + 1, temp_we + M + 1);
		// cout << endl << "ns_list : ";
		// for (int i = 1 ; i < N + 1; i++)
		// 	cout << temp_ns[i] << " ";
		// cout << endl << "we_list : ";
		// for (int i = 1 ; i < M + 1; i++)
		// 	cout << temp_we[i] << " ";
		// cout << endl;
		// int a = 1;
		// int b = 1;
		// while (a < N && b < M)
		// {
		// 	if (temp_ns[a] == temp_we[b])
		// 	{
		// 		a++;
		// 		b++;
		// 		temp++;
		// 	}
		// 	else if (temp_ns[a] < temp_we[b])
		// 		a++;
		// 	else
		// 		b++;
		// }
		ans += temp;
	}
	// print_map(A);

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
