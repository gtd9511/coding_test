#include <iostream>
using namespace std;

int arr[6] = { 1, 1, 2, 2, 2, 8 };
int temp[6] = {0, };

int main()
{
	for (int i = 0; i < 6; i++)
		cin >> temp[i];
	for (int i = 0; i < 6; i++)
		cout << arr[i] - temp[i] << ' ';

	return (0);
}
