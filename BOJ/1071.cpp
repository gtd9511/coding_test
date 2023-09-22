#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int N, ans = 0;
// int arr[1000] = {0, };

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
			;
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


//docker-compose
