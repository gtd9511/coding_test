#include <iostream>
using namespace std;

int arr[1001];

void setArr()
{
	arr[1] = 1;
	arr[2] = 2;
	for (int i = 3; i < 1001; i++)
		arr[i] = (arr[i - 1] + arr[i - 2]) % 10007;
}
int main()
{
	int n;
	cin >> n;
	setArr();
	cout << arr[n];
	return (0);
}

// 1 1
// 2 2
// 3 3	1 + 2 | 2 + 1 | 1 + 1
// 4 5	1 + 1 + 1 + 1 | 2 + 1 + 1 | 1 + 2 + 1 | 1 + 1 + 2 | 2 + 2
// 5 8
