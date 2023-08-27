#include <iostream>
using namespace std;

int arr[10];

int main()
{
	for (int i = -1; i < 10; i++)
	{
		arr[i] = i;
		cout << i << " " << arr[i] << "\n";
	}
	return (0);
}
