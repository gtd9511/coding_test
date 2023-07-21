#include <iostream>
using namespace std;
int arr[10];

int main()
{
	for (int i = 0; i < 10; i++)
	{
		cin >> arr[i];
		arr[i] %= 42;
	}
	int ans = 0;
	for (int i = 0; i < 10; i++)
	{
		bool flag = true;
		for (int j = 0; j < i; j++)
		{
			if (arr[i] == arr[j])
			{
				flag = false;
				break;
			}
		}
		if (flag) ans++;
	}
	cout << ans;
	return (0);
}
