	// i 				1개 		3원
	// i, i + 1 		1개 1개		5원
	// i, i + 1, i + 2 	1개 1개 1개	7원
	// 1 2 3
	// 1 3 2
	// 2 1 3
	// 2 3 1
	// 3 1 2
	// 3 2 1


#include <iostream>

using namespace std;

int N;
int arr[10001] = {0, };
int ans = 0;

void case_1(int n)
{
	arr[n]--;
	ans ++;
}

void case_2(int n)
{
	arr[n]--;
	arr[n + 1]--;
	ans ++;
}

void case_3(int n)
{
	arr[n]--;
	arr[n + 1]--;
	arr[n + 2]--;
	ans ++;
}


int main()
{
	int total = 0;
	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		cin >> arr[i + 1];
		total += arr[i + 1];
	}
	for (int i = 1; i <= N; i++)
	{
	// 	cout << "i : " << i << endl;
		// for (int j = 0; j < N; j++)
		// 	cout << arr[j + 1] << " ";
		// cout << endl;
		while ((arr[i] > 0) && (arr[i + 1] > 0) && (arr[i + 2] > 0))
			case_3(i);
		while ((arr[i] > 0) && (arr[i + 1] > 0))
			case_2(i);
		while ((arr[i] > 0))
			case_1(i);
		// cout << "ans : " << ans << endl;
	}
	ans += 2 * total;
	cout << ans << endl;

	return 0;
}

// 1 4 2 3 1
// 1 2 0 1 1 14 3*2 6
// 0 1 0 0 0 24 2*2 4
// 0 0 0 0 0 27 1*1 1

// 1 4 2 3 1
// 0 3 1 3 1 7 3*1 3
// 0 2 0 2 1 14 3*1 3
// 0 2 0 1 0 19 2*1 2
// 0 0 0 1 0 28 1*3 3

// 1 2 3 2 1
// 0 1 2 2 1 7
// 0 0 1 1 1 14
// 0 0 0 0 0 21


