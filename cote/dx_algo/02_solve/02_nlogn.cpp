#include <iostream>
#include <algorithm>
#include <iterator>
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
	start_flag(A, ns_list, we_list);

	// cout << "****0****" << endl;
	// print_map(A);
	// print_map(flag);
	for (int i = 0; i < Q; i++)
	{
		temp = 1;
		// cout << "&&&&&" << i + 1 << "&&&&&" << endl;
		int r, c, x;
		cin >> r >> c >> x;
		A[r][c] = x;
		if (ns_list[r] < x)
			ns_list[r] = x;
		if (we_list[c] < x)
			we_list[c] = x;
		int* temp_ns = new int [N + 1];
		int* temp_we = new int [M + 1];

		// copy_n(ns_list, N + 1, temp_ns);
		// copy_n(we_list, M + 1, temp_we);
		// sort(temp_ns + 1, temp_ns + N + 1);
		// sort(temp_we + 1, temp_we + M + 1);
		// cout << endl << "ns_list : ";
		// for (int i = 1; i < N + 1; i++)
		// 	cout << ns_list[i] << " ";
		// cout << endl << "we_list : ";
		// for (int i = 1; i < M + 1; i++)
		// 	cout << we_list[i] << " ";
		// cout << endl;
		if (!(r == 1 || c == 1))
		{
			// cout << "***************1***********" << endl;
			// cout << "r : " << r << endl;
			// cout << "c : " << c << endl;

			for (int i = 1; i < r; i++)
				temp_ns[i] = 0;
			for (int i = 1; i < c; i++)
				temp_we[i] = 0;

			for (int i = 1; i < r; i++)
				temp_ns[i] = ns_list[i];
			for (int i = 1; i < c; i++)
				temp_we[i] = we_list[i];

			sort(temp_ns + 1, temp_ns + r);
			sort(temp_we + 1, temp_we + c);
			// cout << endl << "temp_ns_list : ";
			// for (int i = 1 ; i < r; i++)
			// 	cout << temp_ns[i] << " ";
			// cout << endl << "temp_we_list : ";
			// for (int i = 1 ; i < c; i++)
			// 	cout << temp_we[i] << " ";
			// cout << endl;
			int a = 1;
			int b = 1;
			while (a < r && b < c )
			{
				// cout << "r : " << r << endl;
				// cout << "c : " << c << endl;
				// cout << "a : " << a << endl;
				if (temp_ns[a] == temp_we[b] && temp_ns[a] != 0)
				{
					// cout << "UP 1" << endl;
					a++;
					b++;
					temp++;
					// cout << "--------------------------" << endl;
					// cout << "temp_ns[a] : " << temp_ns[a] << endl;
					// cout << "temp_we[b] : " << temp_we[b] << endl;
					// cout << "a : " << a << endl;
					// cout << "b : " << b << endl;
				}
				else if (temp_ns[a] < temp_we[b])
					a++;
				else
					b++;
			}
			// cout << "temp 1 : " << temp << endl;
		}
		if (!(r == N || c == 1))
		{
			// cout << "***************3***********" << endl;
			// cout << "r : " << r << endl;
			// cout << "c : " << c << endl;

			for (int i = 1; i < N -r + 1; i++)
				temp_ns[i] = 0;
			for (int i = 1; i < c; i++)
				temp_we[i] = 0;

			for (int i = 1; i < N - r + 1; i++)
				temp_ns[i] = ns_list[i + r];
			for (int i = 1; i < c; i++)
				temp_we[i] = we_list[i];

			sort(temp_ns + 1, temp_ns + N - r + 1);
			sort(temp_we + 1, temp_we + c);
			// cout << endl << "temp_ns_list : ";
			// for (int i = 1 ; i < N - r + 1; i++)
			// 	cout << temp_ns[i] << " ";
			// cout << endl << "temp_we_list : ";
			// for (int i = 1 ; i < c; i++)
			// 	cout << temp_we[i] << " ";
			// cout << endl;
			int a = 1;
			int b = 1;
			while (a < N - r + 1 && b < c )
			{
				if (temp_ns[a] == temp_we[b] && temp_ns[a] != 0)
				{
					// cout << "UP 3" << endl;
					a++;
					b++;
					temp++;
				}
				else if (temp_ns[a] < temp_we[b])
					a++;
				else
					b++;
			}
			// cout << "temp 3 : " << temp << endl;
		}
		if (!(r == N || c == M))
		{
			// cout << "***************4***********" << endl;
			// cout << "r : " << r << endl;
			// cout << "c : " << c << endl;

			for (int i = 1; i < N -r + 1; i++)
				temp_ns[i] = 0;
			for (int i = 1; i < M -c + 1; i++)
				temp_we[i] = 0;

			for (int i = 1; i < M - c + 1; i++)
				temp_we[i] = we_list[i + c];
			for (int i = 1; i < N - r + 1; i++)
				temp_ns[i] = ns_list[i + r];

			sort(temp_we + 1, temp_we + M - c + 1);
			sort(temp_ns + 1, temp_ns + N - r + 1);
			// cout << endl << "temp_ns_list : ";
			// for (int i = 1 ; i < N -r + 1; i++)
			// 	cout << temp_ns[i] << " ";
			// cout << endl << "temp_we_list : ";
			// for (int i = 1 ; i < M -c + 1; i++)
			// 	cout << temp_we[i] << " ";
			// cout << endl;
			int a = 1;
			int b = 1;
			while (a < N - r + 1 && b < M - c + 1 )
			{
				if (temp_ns[a] == temp_we[b] && temp_ns[a] != 0)
				{
					// cout << "UP 4" << endl;
					a++;
					b++;
					temp++;
				}
				else if (temp_ns[a] < temp_we[b])
					a++;
				else
					b++;
			}
			// cout << "temp4 : " << temp << endl;
		}
		if (!(r == 1 || c == M))
		{
			// cout << "***************2***********" << endl;
			// cout << "r : " << r << endl;
			// cout << "c : " << c << endl;

			for (int i = 1; i < r; i++)
				temp_ns[i] = 0;
			for (int i = 1; i < M -c + 1; i++)
				temp_we[i] = 0;

			for (int i = 1; i < r; i++)
				temp_ns[i] = ns_list[i];
			for (int i = 1; i < M - c + 1; i++)
				temp_we[i] = we_list[i + c];

			sort(temp_ns + 1, temp_ns + r);
			sort(temp_we + 1, temp_we + M - c + 1);
			// cout << endl << "temp_ns_list : ";
			// for (int i = 1 ; i < r; i++)
			// 	cout << temp_ns[i] << " ";
			// cout << endl << "temp_we_list : ";
			// for (int i = 1 ; i < M - c + 1; i++)
			// 	cout << temp_we[i] << " ";
			// cout << endl;
			int a = 1;
			int b = 1;
			while (a < r && b < M - c + 1)
			{
				// cout << "a : " << a << endl;
				// cout << "b : " << b << endl;
				// cout << "r : " << r << endl;
				// cout << "M -c + 1 :" << M -c + 1 << endl;
				if (temp_ns[a] == temp_we[b] && temp_ns[a] != 0)
				{
					// cout << "UP 2" << endl;
					a++;
					b++;
					temp++;
				}
				else if (temp_ns[a] < temp_we[b])
					a++;
				else
					b++;
				// cout << "after a: " << a << endl;
				// cout << "after b: " << b << endl;
			}
			// cout << "temp 2 : " << temp << endl;
		}
		// cout << "temp : " << temp << endl;


		// cout << endl << "ns_list : ";
		// for (int i = 1 ; i < N + 1; i++)
		// 	cout << ns_list[i] << " ";
		// cout << endl << "we_list : ";
		// for (int i = 1 ; i < M + 1; i++)
		// 	cout << we_list[i] << " ";
		// cout << endl;
		// cout << endl << "temp_ns_list : ";
		// for (int i = 1 ; i < N + 1; i++)
		// 	cout << temp_ns[i] << " ";
		// cout << endl << "temp_we_list : ";
		// for (int i = 1 ; i < M + 1; i++)
		// 	cout << temp_we[i] << " ";
		// cout << endl;
		// int a = 1;
		// int b = 1;
		// while (a < N || b < M )
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
