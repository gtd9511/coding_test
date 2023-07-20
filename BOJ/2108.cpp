#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v;
vector<int> v2;
int N, A, B, C, D;
int most[8001] = {0, };
int arr[10];

int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int temp;
		cin >> temp;
		v.push_back(temp);
		A += temp;
		most[temp + 4000]++;
	}
	A = (int)((double)A / (double)N + 0.5);
	if (A < 0)
		A--;
	sort(v.begin(), v.end());
	B = v[N / 2];
	C = 0;
	for (int i = 0; i < 8001; i++)
	{
		if (C < most[i])
			C = most[i];
	}
	for (int i = 0; i < 8001; i++)
	{
		if (C == most[i])
			v2.push_back(i - 4000);
	}
	if (v2.size() == 1)
		C = v2[0];
	else if (v2.size() > 1)
		C = v2[1];
	D = v[N - 1] - v[0];

	cout << A << "\n" << B << "\n" << C << "\n" << D << "\n";
	return (0);
}
