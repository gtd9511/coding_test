#include <iostream>
using namespace std;

int arr[1000001] = {0, };

void set_arr()
{
	arr[1] = 0;
	arr[2] = 1;
	arr[3] = 1;
	for (int i = 1; i < 1000001; i++)
	{
		if (3 * i < 1000001 && (arr[3 * i] == 0 || (arr[3 * i] > arr[i] + 1)))
			arr[3 * i] = arr[i] + 1;
		if (2 * i < 1000001 && (arr[2 * i] == 0 || (arr[2 * i] > arr[i] + 1)))
			arr[2 * i] = arr[i] + 1;
		if (i + 1 < 1000001 && (arr[i + 1] == 0 || (arr[i + 1] > arr[i] + 1)))
			arr[i + 1] = arr[i] + 1;
	}
}

int main()
{
	int N;
	cin >> N;
	set_arr();
	cout << arr[N];
	// cout << ans;
	return (0);
}


// 1	1
// 2	1
// 3	1
// 4	2
// 5	3
// 6	2
// 7	3
// 8	3
//


// 12	4 2 1 3
// 12
