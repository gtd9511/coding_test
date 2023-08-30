#include <iostream>
using namespace std;

int setArr(int n)
{
	if (n == 1)
		return 1;
	if (n == 2)
		return 2;
	if (n == 3)
		return 4;
	else
		return (setArr(n - 1) + setArr(n - 2) + setArr(n - 3));
}

// n
// 1 + n - 1
// 2 + n - 2
// 3 + n - 3
// 4
// 1 + 3 > 4
// 2 + 2 > 2
// 3 + 1 > 1


int main()
{
	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int temp;
		cin >> temp;
		cout << setArr(temp) << "\n";
	}
	return (0);
}
