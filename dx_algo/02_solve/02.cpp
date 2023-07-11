#include <iostream>

using namespace std;

int N = 0;
int M, Q, T;
int ans;
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

// int solve(int** A, bool** flag)
// {
// 	int temp_x = 0;
// 	int temp_y = 0;
// 	int min = 10000001;
// 	for (int i = 1; i < N + 1; i++)
// 	{
// 		for (int j = 1; j < M + 1; j++)
// 		{
// 			if (min > A[i][j] && A[i][j] > 0 && flag[i][j] != 1)
// 			{
// 				min = A[i][j];
// 				temp_x = i;
// 				temp_y = j;
// 			}
// 		}
// 	}
// 	flag[temp_x][temp_y] = 1;
// 	for (int i = 1; i < N + 1; i++)
// 	{
// 		// A[i][temp_y] = 0;
// 		if(flag[i][temp_y] == 1 && i != temp_x)
// 		{
// 			min = 0;
// 			ans--;
// 			break;
// 		}
// 	}
// 	for (int j = 1; j < M + 1; j++)
// 	{
// 		// A[temp_x][j] = 0;
// 		if (flag[temp_x][j] == 1 && j != temp_y)
// 		{
// 			min = 0;
// 			ans--;
// 			break;
// 		}
// 	}
// 	// A[temp_x][temp_y] = 10000001;
// 	// print_map(A);
// 	// print_bool(flag);
// 	// cout << "min : " << min << endl;
// 	// cout << "temp_x : " << temp_x << endl;
// 	// cout << "temp_y : " << temp_y << endl;
// 	// cout << "ans : " << ans << endl;
// 	return (min);
// }

int solve(int** A, bool** flag)
{
	int temp_x = 0;
	int temp_y = 0;
	int min = 10000001;
	for (int i = 1; i < N + 1; i++)
	{
		for (int j = 1; j < M + 1; j++)
		{
			if (min > A[i][j] && A[i][j] > 0 && flag[i][j] != 1)
			{
				min = A[i][j];
				temp_x = i;
				temp_y = j;
			}
		}
	}
	flag[temp_x][temp_y] = 1;
	for (int i = 1; i < N + 1; i++)
	{
		// A[i][temp_y] = 0;
		if(flag[i][temp_y] == 1 && i != temp_x)
		{
			min = 0;
			ans--;
			break;
		}
	}
	for (int j = 1; j < M + 1; j++)
	{
		// A[temp_x][j] = 0;
		if (flag[temp_x][j] == 1 && j != temp_y)
		{
			min = 0;
			ans--;
			break;
		}
	}
	// A[temp_x][temp_y] = 10000001;
	// print_map(A);
	// print_bool(flag);
	// cout << "min : " << min << endl;
	// cout << "temp_x : " << temp_x << endl;
	// cout << "temp_y : " << temp_y << endl;
	// cout << "ans : " << ans << endl;
	return (min);
}

int each_case()
{
	ans = 0;
	int totaltime = 0;
	cin >> N >> M >> Q;

	if (N > M)
		totaltime = M;
	else
	 	totaltime = N;

	ans += totaltime;
	// cout << endl << "Low : " << ans << endl;
	int** A = new int*[N + 1];
	bool** flag = new bool*[N + 1];
	for (int i = 0; i < N + 1; i++)
	{
		A[i] = new int[M + 1];
		flag[i] = new bool[M + 1];
	}

	for (int i = 1; i < N + 1; i++)
	{
		for (int j = 1; j < M + 1; j++)
		{
			cin >> A[i][j];
			flag[i][j] = 0;
		}
	}
	// print_map(A);
	for (int i = 0; i < Q; i++)
	{
		int r, c, x;
		cin >> r >> c >> x;
		A[r][c] = x;
	}
	// print_map(A);
	for (int i = 0; i < totaltime; i++)
	{
		ans += solve(A, flag);
		// cout << "total : " << ans << endl;
	}
	// ans += total;

	for (int i = 0; i < N; i++)
		delete[] A[i];
	delete[] A;

	return (ans);
}

// int each_case()
// {
// 	int ans = 0;
// 	int index = 0;
// 	int min = 10000001;
// 	for (int i = 0; i < M; i++)
// 		A[i] = 0;

// 	cin >> N >> M >> Q;
// 	for (int i = 1; i < M + 1; i++)
// 	{
// 		cin >> A[i];
// 		if (min > A[i])
// 		{
// 			min = A[i];
// 			index = i;
// 		}
// 		else
// 		 	A[i] = 0;
// 	}
// 	minA[index] = min;


// }

int main()
{
	cin >> T;
	for (int i = 1; i <= T; i++)
	{
		int ans = 0;
		ans = each_case();
		cout << "#" << i << " " << ans << endl;
	}
	return (0);
}
