#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int N;
int arr[45];

void setarr()
{
	arr[0] = 1;
	arr[1] = 1;
	for (int i = 2; i < 45; i++)
		arr[i] = arr[i - 1] + arr[i - 2];
}

int main()
{
	setarr();
	cin >> N;
	while (N--)
	{
		vector<int> temp;
		int n;
		cin >> n;
		while (n)
		{
			temp.push_back(arr[(upper_bound(arr, arr+45, n) - arr - 1)]);
			n -= temp.back();
		}
		//-----------
		// for (int i = 44; i >= 0; i--)
		// {
		// 	if (n >= arr[i])
		// 	{
		// 		temp.push_back(arr[i]);
		// 		n -= arr[i];
		// 	}
		// }
		// //-----------
		for (int i = temp.size() - 1; i >= 0; i--)
			cout << temp[i] << " ";
		cout << "\n";
	}
	return (0);
}


// 12
// 1 1 2 3 5 8
// 2 5 5
// 1 1 1 1 1 1 1 1 1 1
// 2 2 2 2 2
//
