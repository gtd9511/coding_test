#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int N, ans = 0;
// int arr[1000] = {0, };

void swap(int &a, int &b)
{
	int temp = a;
	a = b;
	b = temp;
}

int main()
{
	cin >> N;
	vector <int> v(N);
	for (int i = 0; i < N; i++)
		cin >> v[i];

	sort(v.begin(), v.end());

	for (int i = 0; i < N - 1; i++)
	{
		if (v[i] + 1 == v[i + 1])
		{
			int temp = i + 1;
			bool flag = 0;

			while (v[temp] == v[i + 1])
				temp++;
			if (temp == N - 1)
				swap(v[i], v[i + 1]);
			else
			{

			}

				while (v[temp] == v[i + 1])
					temp++;
				cout << "temp : " << temp << endl;
				cout << "v[i + 1]  : " << v[i + 1] << endl;
				if (temp != N - 1)
				{
					swap(v[i + 1], v[temp]);
					flag = 1;
				}
				if (!flag)
				{
					swap(v[i], v[temp - 1]);
					flag = 1;
				}
			if (!flag)
			{
				swap(v[i], v[i + 1]);
			}
		}
	}

	for (int i = 0; i < v.size(); i++)
		cout << v[i] << " ";

	return (0);
}

//123

//1234
//1324
//111222

//112122
//


// 1111122
// 2111121
// 2211111

// 1122222
// 2122221
// 2222211

